--- extensions/typeaheadfind/src/nsTypeAheadFind.h.orig	Mon Jun 27 18:02:03 2005
+++ extensions/typeaheadfind/src/nsTypeAheadFind.h
@@ -197,6 +197,9 @@
 
   nsCString mNotFoundSoundURL;
 
+  // Move the sound enabled boolean out for all methods to access.
+  PRBool mIsSoundEnabled;
+
   // PRBool's are used instead of PRPackedBool's where the address of the
   // boolean variable is getting passed into a method. For example:
   // GetBoolPref("accessibility.typeaheadfind.linksonly", &mLinksOnlyPref);
