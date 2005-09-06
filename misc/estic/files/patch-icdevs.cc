--- estic/icdevs.cc.orig	Sat Feb 26 18:30:40 2000
+++ estic/icdevs.cc	Sat Feb 26 18:32:24 2000
@@ -299,8 +299,8 @@
 String DevListBox::RerouteName (unsigned Val, unsigned char* Num)
 // Map the reroute capability to a string with fixed length
 {
-    const StringLength = 11;
-    const PadLength = 12;
+    const int StringLength = 11;
+    const int PadLength = 12;
     String Res (PadLength);
 
     if (Val == 0x00) {
@@ -427,37 +427,37 @@
     static const String StgPosName = "EditDevConfig.ConfigMenue.Position";
 
     // Menue constants
-    const miDialCaps      = 10;
-    const miService       = 20;
-    const miReroute       = 30;
-    const miChargePulse   = 40;
-    const miPIN           = 50;
-    const miTerminalMode  = 60;
-    const miKnockInt      = 70;
-    const miKnockExt      = 80;
-    const miKnockTFE      = 90;
-    const miKnockInt21    = 1000;
-    const miKnockInt22    = 1010;
-    const miKnockInt23    = 1020;
-    const miKnockInt24    = 1030;
-    const miKnockInt25    = 1040;
-    const miKnockInt26    = 1050;
-    const miKnockInt27    = 1060;
-    const miKnockInt28    = 1070;
-    const miKnockMSN0     = 1100;
-    const miKnockMSN1     = 1110;
-    const miKnockMSN2     = 1120;
-    const miKnockMSN3     = 1130;
-    const miKnockMSN4     = 1140;
-    const miKnockMSN5     = 1150;
-    const miKnockMSN6     = 1160;
-    const miKnockMSN7     = 1170;
-    const miKnockMSN8     = 1180;
-    const miKnockMSN9     = 1190;
-    const miKnockTFE1     = 1200;
-    const miKnockTFE2     = 1210;
-    const miKnockTFE3     = 1220;
-    const miKnockTFE4     = 1230;
+    const int miDialCaps      = 10;
+    const int miService       = 20;
+    const int miReroute       = 30;
+    const int miChargePulse   = 40;
+    const int miPIN           = 50;
+    const int miTerminalMode  = 60;
+    const int miKnockInt      = 70;
+    const int miKnockExt      = 80;
+    const int miKnockTFE      = 90;
+    const int miKnockInt21    = 1000;
+    const int miKnockInt22    = 1010;
+    const int miKnockInt23    = 1020;
+    const int miKnockInt24    = 1030;
+    const int miKnockInt25    = 1040;
+    const int miKnockInt26    = 1050;
+    const int miKnockInt27    = 1060;
+    const int miKnockInt28    = 1070;
+    const int miKnockMSN0     = 1100;
+    const int miKnockMSN1     = 1110;
+    const int miKnockMSN2     = 1120;
+    const int miKnockMSN3     = 1130;
+    const int miKnockMSN4     = 1140;
+    const int miKnockMSN5     = 1150;
+    const int miKnockMSN6     = 1160;
+    const int miKnockMSN7     = 1170;
+    const int miKnockMSN8     = 1180;
+    const int miKnockMSN9     = 1190;
+    const int miKnockTFE1     = 1200;
+    const int miKnockTFE2     = 1210;
+    const int miKnockTFE3     = 1220;
+    const int miKnockTFE4     = 1230;
 
 
     // Save the configuration
