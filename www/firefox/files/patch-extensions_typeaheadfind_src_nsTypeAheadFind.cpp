$FreeBSD$

--- extensions/typeaheadfind/src/nsTypeAheadFind.cpp.orig	Wed Nov 19 01:20:47 2003
+++ extensions/typeaheadfind/src/nsTypeAheadFind.cpp	Tue Feb 10 02:52:26 2004
@@ -323,11 +323,11 @@
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
@@ -758,7 +758,7 @@
     }
     else {
       // No find string to backspace in!
-      if (mIsBackspaceProtectOn) {
+      if (mIsBackspaceProtectOn && mIsSoundEnabled) {
         // This flag should be on only if the last key was a backspace.
         // It keeps us from accidentally hitting backspace too many times and
         // going back in history when we really just wanted to clear 
@@ -1012,7 +1012,9 @@
 
     // Error sound (don't fire when backspace is pressed, they're 
     // trying to correct the mistake!)
-    PlayNotFoundSound();
+    if (mIsSoundEnabled) {
+      PlayNotFoundSound();
+    }
 
     // Remove bad character from buffer, so we can continue typing from
     // last matched character
@@ -1059,7 +1061,7 @@
 void
 nsTypeAheadFind::PlayNotFoundSound()
 {
-  if (mNotFoundSoundURL.IsEmpty())    // no sound
+  if (mNotFoundSoundURL.IsEmpty() || !mIsSoundEnabled)    // no sound
     return;
   if (!mSoundInterface) {
     mSoundInterface = do_CreateInstance("@mozilla.org/sound;1");
