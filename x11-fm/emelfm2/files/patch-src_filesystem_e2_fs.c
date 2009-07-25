--- src/filesystem/e2_fs.c.orig	2009-07-24 08:00:32.000000000 +0200
+++ src/filesystem/e2_fs.c	2009-07-24 08:01:05.000000000 +0200
@@ -2570,7 +2570,7 @@
 gint e2_fs_writeflush (gint file_desc)
 {
 	gint res;
-	res = fdatasync (file_desc);
+	res = fsync (file_desc);
 	if (res == -1 && errno == EINVAL)
 		res = 0;
 	return res;
