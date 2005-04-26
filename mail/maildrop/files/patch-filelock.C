--- maildrop/filelock.C.orig	Sat Apr 29 03:17:45 2000
+++ maildrop/filelock.C	Fri Apr 15 13:09:25 2005
@@ -64,7 +64,7 @@
 		// you're writing to a device file, you know what you're doing.
 
 		if (fstat(fd, &stat_buf) >= 0 && (
-			S_ISREG(stat_buf.st_mode) || S_ISDIR(stat_buf.st_mode)))
+			S_ISCHR(stat_buf.st_mode) || S_ISBLK(stat_buf.st_mode)))
 		{
 			return;
 		}
