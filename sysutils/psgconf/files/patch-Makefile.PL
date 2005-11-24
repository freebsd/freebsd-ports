--- ./Makefile.PL.orig	Wed Feb 18 14:44:59 2004
+++ ./Makefile.PL	Wed Feb 18 14:45:16 2004
@@ -20,7 +20,7 @@
 
 my ($etc_dir, $share_dir);
 
-$etc_dir	= '/etc';
+$etc_dir	= '$(PREFIX)/etc';
 $share_dir	= '$(PREFIX)/share/psgconf';
 
 GetOptions(
