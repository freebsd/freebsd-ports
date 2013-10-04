--- libs/maildrop/filelock.C.orig	2013-08-25 20:54:20.000000000 +0200
+++ libs/maildrop/filelock.C	2013-10-01 17:26:36.724456433 +0200
@@ -63,7 +63,7 @@
 		// you're writing to a device file, you know what you're doing.
 
 		if (fstat(fd, &stat_buf) >= 0 && (
-			S_ISREG(stat_buf.st_mode) || S_ISDIR(stat_buf.st_mode)))
+			S_ISCHR(stat_buf.st_mode) || S_ISBLK(stat_buf.st_mode)))
 		{
 			return;
 		}
