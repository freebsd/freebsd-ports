fix sh: Syntax error: Unterminated quoted string

--- Makefile.PL.orig	2025-07-13 09:16:55 UTC
+++ Makefile.PL
@@ -28,8 +28,8 @@ my $pm_filter = $use_unicode
 }
 
 my $pm_filter = $use_unicode
-    ? q{perl -pi -e "s!UNI_YES ! !g;s!UNI_NO  !\\#!g"}
-    : q{perl -pi -e "s!UNI_NO  ! !g;s!UNI_YES !\\#!g"};
+    ? q{sed -e "s/UNI_YES//g;s/UNI_NO.*//g"}
+    : q{sed -e "s/UNI_NO//g;s/UNI_YES.*//g"};
 
 WriteMakefile(
     NAME         => 'PDF::Template',
