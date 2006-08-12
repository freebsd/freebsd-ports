--- libdal/file.c.orig	Thu Dec 12 21:32:34 2002
+++ libdal/file.c	Sat Aug 12 15:35:27 2006
@@ -14,6 +14,7 @@
 
 #if defined(__freebsd__)
 #  define O_LARGEFILE 0
+#  include <sys/disk.h>
 #endif
 
 #ifndef DJGPP
@@ -154,6 +155,15 @@
     
 #endif
     
+#ifdef DIOCGMEDIASIZE
+
+    if (ioctl(*((int *)dal->entity), DIOCGMEDIASIZE, &size) >= 0)
+        return (count_t)(size / dal->blocksize);
+
+    file_save_error(dal);
+    
+#endif
+
     if ((max_off = lseek(*((int *)dal->entity), 0, SEEK_END)) == (off_t)-1) {
 	file_save_error(dal);
 	return 0;
