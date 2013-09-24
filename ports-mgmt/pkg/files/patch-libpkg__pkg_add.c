--- libpkg/pkg_add.c.orig	2013-07-06 12:48:19.000000000 +0200
+++ libpkg/pkg_add.c	2013-09-24 14:22:38.561062335 +0200
@@ -100,7 +100,7 @@
 	return (retcode);
 }
 
-static int
+int
 do_extract_mtree(char *mtree, const char *prefix)
 {
 	struct archive *a = NULL;
