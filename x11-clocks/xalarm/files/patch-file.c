--- file.c.orig	1995-07-12 08:24:22.000000000 -0700
+++ file.c	2015-10-25 01:08:02.787449291 -0700
@@ -229,7 +229,7 @@
 	lock.l_type = F_WRLCK;
 	lock.l_whence = SEEK_SET;
 	lock.l_start = lock.l_len = (long) 0;
-	fcntl (fileno (file), F_SETFL, O_SYNC);
+	fcntl (fileno (file), F_SETFL, O_FSYNC);
 	fcntl (fileno (file), F_SETLKW, &lock);
 #endif
 
