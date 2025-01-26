#include<Servo.h>
#include<SoftwareSerial.h>
SoftwareSerial mySerial(A5,A4); //TX,RX
char bt;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;
Servo servo12;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);
  servo7.attach(8);
  servo8.attach(9);
  servo9.attach(10);
  servo10.attach(11);
  servo11.attach(12);
  servo12.attach(13);
  initial_position();
  delay(3000);

}

void loop() {
  if(mySerial.available()>0) {
    bt=mySerial.read();
    Serial.println(bt);
  }
  if(bt=='1') {
    hi_Lside();
    initial_position();
  }
}

void initial_position() {
  servo1.write(88);
  servo2.write(84);   
  servo3.write(85);
  servo4.write(78);

  servo5.write(83); 
  servo6.write(100);
  servo7.write(96);
  servo8.write(83);
  
  servo9.write(90);
  servo10.write(0); 
  servo11.write(90);
  servo12.write(0);
}    

void hi_Lside() {
  for(int i=0; i<=160; i++) {
    servo10.write(i);
    delay(15);
  }
  for(int i=160; i>=90; i--) {
    servo10.write(i);
    delay(15);
  }
  for(int i=90; i<=160; i++) {
    servo10.write(i);
    delay(15);
  }
  for(int i=160; i>=0; i--) {
    servo10.write(i);
    delay(15);
  }
}