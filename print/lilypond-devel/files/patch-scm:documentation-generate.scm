--- scm/documentation-generate.scm.orig	Mon Oct  6 15:28:49 2003
+++ scm/documentation-generate.scm	Mon Oct  6 15:29:09 2003
@@ -43,7 +43,7 @@
 (display
  (string-append
   "@c -*-texinfo-*-"
-  (texi-file-head "LilyPond program-reference" outname "(lilypond-internals.info)")
+  (texi-file-head "LilyPond program-reference" file-name "(lilypond-internals.info)")
   "
 
 @ifhtml
