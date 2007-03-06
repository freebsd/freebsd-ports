--- unionfs.c.orig	Tue Mar  6 10:40:41 2007
+++ unionfs.c	Tue Mar  6 10:46:09 2007
@@ -192,11 +192,7 @@
 
 	int res;
 	if (isdatasync) {
-#ifdef _POSIX_SYNCHRONIZED_IO
-		res = fdatasync(fi->fh);
-#else
 		res = fsync(fi->fh);
-#endif
 	} else {
 		res = fsync(fi->fh);
 	}
