//#include <DHT.h>
//#include <DHT_U.h>
//#include <RTCZero.h>
//#include <LiquidCrystal.h>
//#include <Stepper.h>

volatile unsigned char* port_b = (unsigned char*) 0x25; 
//note to use the pins SDA/SCL pins 20 and 21
volatile unsigned char* waterPin = (unsigned char*) 0x61;
volatile unsigned char* powerWaterPin = (unsigned char*) 0x07;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  *powerWaterPin |= 0x01 << 7;

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(Waterlevel());
}

int Waterlevel() {
  int value;
  *waterPin |= 0x01 << 7;
  value = analogRead(waterPin);
  *waterPin &= ~(0x01 << 7); 
  return value;
}
//
//void Idle(){
//
//
//  
//}
//
//void Disabled(){
//
//
//  
//}
//
//void Error(){
//
//
//  
//}
