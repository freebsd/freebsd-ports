--- bsd/intmeter.cc.orig	Sat Jun 10 17:37:21 2000
+++ bsd/intmeter.cc	Sat Jun 10 17:37:51 2000
@@ -22,9 +22,9 @@
   //  out the door.
   //  Same goes for platforms (like Alpha) with more than 16
   //  interrupts.
-  : BitMeter( parent, "INTS", "IRQs", 16 /*BSDNumInts()*/, 
+  : BitMeter( parent, "INTS", "IRQs", BSDNumInts(), 
               dolegends, dousedlegends ) {
-  for ( int i = 0 ; i < 16 ; i++ )
+  for ( int i = 0 ; i < BSDNumInts(); i++ )
     irqs_[i] = lastirqs_[i] = 0;
 }
 
@@ -34,7 +34,7 @@
 void IntMeter::checkevent( void ){
   getirqs();
 
-  for ( int i = 0 ; i < 16 ; i++ ){
+  for ( int i = 0 ; i < BSDNumInts() ; i++ ){
     bits_[i] = ((irqs_[i] - lastirqs_[i]) != 0);
     lastirqs_[i] = irqs_[i];
   }

