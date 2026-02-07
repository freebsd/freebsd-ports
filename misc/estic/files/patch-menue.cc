--- spunk/menue.cc.orig	1997-01-26 17:17:32 UTC
+++ spunk/menue.cc
@@ -495,8 +495,8 @@ void GenericMenue::DynamicRight ()
 
 i16 GenericMenue::GetChoice ()
 {
-    const AltNextKeyCode = MaxUserID + 1;
-    const AltPrevKeyCode = MaxUserID + 2;
+    const int AltNextKeyCode = MaxUserID + 1;
+    const int AltPrevKeyCode = MaxUserID + 2;
 
 
     // Remember old window state
