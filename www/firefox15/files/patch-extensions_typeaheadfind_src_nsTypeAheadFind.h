$FreeBSD$
  $MCom: ports/www/firefox/files/patch-extensions_typeaheadfind_src_nsTypeAheadFind.h,v 1.7 2005/11/11 00:15:48 ahze Exp $

--- extensions/typeaheadfind/src/nsTypeAheadFind.h.orig	Fri May 23 22:00:33 2003
+++ extensions/typeaheadfind/src/nsTypeAheadFind.h	Mon Feb  9 22:21:43 2004
@@ -194,6 +194,9 @@
 
   nsCString mNotFoundSoundURL;
 
+  // Move the sound enabled boolean out for all methods to access.
+  PRBool mIsSoundEnabled;
+
   // PRBool's are used instead of PRPackedBool's where the address of the
   // boolean variable is getting passed into a method. For example:
   // GetBoolPref("accessibility.typeaheadfind.linksonly", &mLinksOnlyPref);
