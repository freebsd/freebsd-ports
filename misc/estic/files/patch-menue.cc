--- spunk/menue.cc.orig	Sat Feb 26 17:58:13 2000
+++ spunk/menue.cc	Sat Feb 26 17:58:32 2000
@@ -495,8 +495,8 @@
 
 i16 GenericMenue::GetChoice ()
 {
-    const AltNextKeyCode = MaxUserID + 1;
-    const AltPrevKeyCode = MaxUserID + 2;
+    const int AltNextKeyCode = MaxUserID + 1;
+    const int AltPrevKeyCode = MaxUserID + 2;
 
 
     // Remember old window state
