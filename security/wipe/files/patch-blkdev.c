--- blkdev.c.orig	2009-04-06 06:09:27.000000000 +0400
+++ blkdev.c	2015-02-03 23:00:08.000000000 +0300
@@ -46,7 +46,9 @@
 
 #ifdef HAVE_SYS_DISKLABEL_H
 # include <sys/disklabel.h>
-# define BSD_BLKDEV
+# ifdef DIOCGDINFO
+#  define BSD_BLKDEV
+# endif
 #endif
 
 #ifndef LINUX_BLKDEV
@@ -141,6 +143,10 @@
   int code;
 
 #ifdef BSD_BLKDEV
+  struct partinfo {
+    struct disklabel *disklab;
+    struct partition *part;
+  };
   struct partinfo pinfo;
 #endif
 
@@ -173,7 +179,7 @@
     }
 
 #ifdef BSD_BLKDEV
-  if (ioctl(f->fd, DIOCGPART, &pinfo))
+  if (ioctl(f->fd, DIOCGDINFO, &pinfo))
     {
       fprintf(stderr, "\r%s: ioctl failed, can't get disklabel for `%s': %s\n",
 	      argvzero, f->name, strerror(errno));
