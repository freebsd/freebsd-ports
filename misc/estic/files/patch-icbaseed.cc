--- estic/icbaseed.cc.orig	Sat Nov 30 01:00:44 1996
+++ estic/icbaseed.cc	Tue Sep  6 09:54:21 2005
@@ -451,26 +451,26 @@
 // otherwise, Changed is left untouched.
 {
     // ID's of menue items for EditBaseConfig
-    const miIstecType           =  10;
-    const miProtocol            =  20;
-    const miExtLevel            =  30;
-    const miMusic               =  40;
-    const miConnection          =  50;
-    const miNumber1             =  60;
-    const miNumber2             =  70;
-    const miTFEAssignment       =  80;
-    const miQueryLoc            =  90;
-    const miMSN                 = 100;
-    const miMSNGroups           = 110;
-    const miEAZGroups           = 120;
-    const miExternalMusicPort   = 130;
-    const miCountryCode         = 140;
-    const miSignaling           = 150;
+    const int miIstecType           =  10;
+    const int miProtocol            =  20;
+    const int miExtLevel            =  30;
+    const int miMusic               =  40;
+    const int miConnection          =  50;
+    const int miNumber1             =  60;
+    const int miNumber2             =  70;
+    const int miTFEAssignment       =  80;
+    const int miQueryLoc            =  90;
+    const int miMSN                 = 100;
+    const int miMSNGroups           = 110;
+    const int miEAZGroups           = 120;
+    const int miExternalMusicPort   = 130;
+    const int miCountryCode         = 140;
+    const int miSignaling           = 150;
 
     // Values for the miMusic toggle item
-    const musOff                = 0;
-    const musInternal           = 1;
-    const musExternal           = 2;
+    const int musOff                = 0;
+    const int musInternal           = 1;
+    const int musExternal           = 2;
 
 
 
