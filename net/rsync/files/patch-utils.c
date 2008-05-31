--- util.c.orig	2008-05-30 20:02:16.000000000 +0400
+++ util.c	2008-05-30 20:04:01.000000000 +0400
@@ -582,7 +582,7 @@
 	} else
 		use_buf = glob.arg_buf;
 
-	if (from_glob || arg) {
+	if (from_glob || (arg && len)) {
 		STRUCT_STAT st;
 		int is_dir;
 
