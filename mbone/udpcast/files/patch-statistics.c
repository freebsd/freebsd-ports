--- statistics.c.orig	Tue Jul 20 10:46:11 2004
+++ statistics.c	Tue Jul 20 12:00:59 2004
@@ -37,7 +37,7 @@
 static void printFilePosition(int fd) {
 #ifndef __CYGWIN__
     if(fd != -1) {
-	loff_t offset = lseek64(fd, 0, SEEK_CUR);
+	off_t offset = lseek(fd, 0, SEEK_CUR);
 	printLongNum(offset);
     }
 #endif
