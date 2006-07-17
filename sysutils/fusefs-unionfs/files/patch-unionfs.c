--- unionfs.c.orig	Sun Jul 16 19:02:07 2006
+++ unionfs.c	Sun Jul 16 19:05:45 2006
@@ -189,9 +189,13 @@
 	if (stats_enabled && strcmp(path, STATS_FILENAME) == 0) return 0;
 
 	int res;
+#if FUSE_USE_VERSION >= 26
 	if (isdatasync) {
 		res = fdatasync(fi->fh);
 	} else {
+#else
+	{
+#endif
 		res = fsync(fi->fh);
 	}
 
