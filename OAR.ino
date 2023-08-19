#include <Servo.h>
#include <NewPing.h>

Servo neck;
NewPing eye(7, 8, 50);



const int IN1 = 9;
const int IN2 = 10;
const int IN3 = 11;
const int IN4 = 12;

const int ENA = 5;
const int ENB = 3;


void IsThere(int i) {
  
  int distance = eye.ping_cm();
  Serial.println(distance);
  
  if(distance > 0 && distance <= 20){
     analogWrite(ENA, 0);
     analogWrite(ENB, 0);

     delay(500);

    for(int j = i; j<180; j++) {
      neck.write(j);       
    }
    delay(300);
    int right = eye.ping_cm();
    Serial.println(right); 
    delay(300);
    
    for(int j = 179; j>0; j--) {
      neck.write(j);
    }
    delay(300);
    int left = eye.ping_cm();
    Serial.println(left);
    delay(300);
    
    for(int j = 1; j<=90; j++) {
      neck.write(j);
    }

    if(right <= 7 && left <=7) {
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(150);
    }

    
    else if(right > left) {
      analogWrite(ENA, 100);
      analogWrite(ENB, 150);
      
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(200);

      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    }

    else if(left > right) {
      analogWrite(ENA, 150);
      analogWrite(ENB, 100);
      
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(200);

      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    }
    }
}



void setup() {

  Serial.begin(9600);

  neck.attach(6);
  pinMode(6, OUTPUT);

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
}

void loop() {

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  
  for (int i = 70; i<=110; i++) {
    neck.write(i);
    delay(7);

    IsThere(i);
    
  }
  delay(100);

  
  for (int i = 110; i<=70; i--) {
    neck.write(i);
    delay(7);

    IsThere(i);
    
  }
  delay(100);

  
}
