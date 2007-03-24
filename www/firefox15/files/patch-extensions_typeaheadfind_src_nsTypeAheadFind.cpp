--- extensions/typeaheadfind/src/nsTypeAheadFind.cpp.orig	Tue Jun 28 19:03:59 2005
+++ extensions/typeaheadfind/src/nsTypeAheadFind.cpp
@@ -318,11 +318,11 @@
   prefBranch->GetBoolPref("accessibility.typeaheadfind.startlinksonly",
                           &mStartLinksOnlyPref);
 
-  PRBool isSoundEnabled = PR_TRUE;
+  mIsSoundEnabled = PR_TRUE;
   prefBranch->GetBoolPref("accessibility.typeaheadfind.enablesound",
-                           &isSoundEnabled);
+                           &mIsSoundEnabled);
   nsXPIDLCString soundStr;
-  if (isSoundEnabled) {
+  if (mIsSoundEnabled && mIsSoundEnabled) {
     prefBranch->GetCharPref("accessibility.typeaheadfind.soundURL",
                              getter_Copies(soundStr));
   }
@@ -757,7 +757,7 @@
     }
     else {
       // No find string to backspace in!
-      if (mIsBackspaceProtectOn) {
+      if (mIsBackspaceProtectOn && mIsSoundEnabled) {
         // This flag should be on only if the last key was a backspace.
         // It keeps us from accidentally hitting backspace too many times and
         // going back in history when we really just wanted to clear 
@@ -1022,7 +1022,9 @@
 
     // Error sound (don't fire when backspace is pressed, they're 
     // trying to correct the mistake!)
-    PlayNotFoundSound();
+    if (mIsSoundEnabled) {
+      PlayNotFoundSound();
+    }
 
     // Remove bad character from buffer, so we can continue typing from
     // last matched character
@@ -1069,7 +1071,7 @@
 void
 nsTypeAheadFind::PlayNotFoundSound()
 {
-  if (mNotFoundSoundURL.IsEmpty())    // no sound
+  if (mNotFoundSoundURL.IsEmpty() || !mIsSoundEnabled)    // no sound
     return;
   if (!mSoundInterface) {
     mSoundInterface = do_CreateInstance("@mozilla.org/sound;1");
