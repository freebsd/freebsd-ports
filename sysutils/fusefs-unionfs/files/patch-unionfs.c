--- unionfs.c.orig	Mon Aug  7 07:20:13 2006
+++ unionfs.c	Tue Aug  8 13:53:17 2006
@@ -188,12 +188,7 @@
 
 	if (stats_enabled && strcmp(path, STATS_FILENAME) == 0) return 0;
 
-	int res;
-	if (isdatasync) {
-		res = fdatasync(fi->fh);
-	} else {
-		res = fsync(fi->fh);
-	}
+	int res = fsync(fi->fh);
 
 	if (res == -1) return -errno;
 
