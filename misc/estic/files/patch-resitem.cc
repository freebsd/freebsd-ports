--- spunk/resitem.cc.orig	1997-02-21 11:05:30 UTC
+++ spunk/resitem.cc
@@ -1539,16 +1539,16 @@ void ResEditApp::ItemMenue (WindowItem* 
 // Data edit menue
 {
     // Menue IDs
-    const miID          = 10;
-    const miText        = 20;
-    const miState       = 30;
-    const miAccelKey    = 40;
-    const miHelpKey     = 50;
-    const miCharset     = 60;
-    const miLimits      = 70;
-    const miSubMenue    = 80;
-    const miToggleText  = 90;
-    const miToggleCount = 100;
+    const int miID          = 10;
+    const int miText        = 20;
+    const int miState       = 30;
+    const int miAccelKey    = 40;
+    const int miHelpKey     = 50;
+    const int miCharset     = 60;
+    const int miLimits      = 70;
+    const int miSubMenue    = 80;
+    const int miToggleText  = 90;
+    const int miToggleCount = 100;
 
     // Load the menue from the resource
     Menue* M = (Menue*) LoadResource ("@RESITEM.ItemDataMenue");
@@ -1785,13 +1785,13 @@ void ResEditApp::ChangeLimits (WindowIte
 
 void ResEditApp::ChangeCharset (WindowItem* Item)
 {
-    const miReset       = 1;
-    const miAddDigits   = 2;
-    const miAddHex      = 3;
-    const miAddAlpha    = 4;
-    const miAddAll      = 5;
-    const miCustom      = 6;
-    const miAllowEmpty  = 7;
+    const int miReset       = 1;
+    const int miAddDigits   = 2;
+    const int miAddHex      = 3;
+    const int miAddAlpha    = 4;
+    const int miAddAll      = 5;
+    const int miCustom      = 6;
+    const int miAllowEmpty  = 7;
 
 
     // Only RStringItem and TextEdits are allowed to change the charset
