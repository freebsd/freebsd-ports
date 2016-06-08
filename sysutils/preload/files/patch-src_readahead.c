--- src/readahead.c.orig	2014-04-10 14:41:02.971372980 -0400
+++ src/readahead.c	2014-04-10 14:41:06.860935336 -0400
@@ -30,7 +30,9 @@
 #ifdef HAVE_LINUX_FS_H
 #include <linux/fs.h>
 #endif
-
+#ifndef __LINUX__
+#include <fcntl.h>
+#endif
 static void
 set_block(preload_map_t *file, gboolean use_inode)
 {
@@ -152,8 +154,12 @@
 	   );
   if (fd >= 0)
     {
-      readahead(fd, offset, length);
 
+#ifndef __LINUX__ 					
+  posix_fadvise(fd,offset,length,POSIX_FADV_WILLNEED);  
+#else 
+      readahead(fd, offset, length);
+#endif
       close (fd);
     }
 
