--- blkdev.c.orig	2009-04-06 02:09:27 UTC
+++ blkdev.c
@@ -46,7 +46,9 @@
 
 #ifdef HAVE_SYS_DISKLABEL_H
 # include <sys/disklabel.h>
-# define BSD_BLKDEV
+# ifdef DIOCGDINFO
+#  define BSD_BLKDEV
+# endif
 #endif
 
 #ifndef LINUX_BLKDEV
@@ -141,6 +143,10 @@ public int destroy_blkdev(struct file_s 
   int code;
 
 #ifdef BSD_BLKDEV
+  struct partinfo {
+    struct disklabel *disklab;
+    struct partition *part;
+  };
   struct partinfo pinfo;
 #endif
 
@@ -173,7 +179,7 @@ public int destroy_blkdev(struct file_s 
     }
 
 #ifdef BSD_BLKDEV
-  if (ioctl(f->fd, DIOCGPART, &pinfo))
+  if (ioctl(f->fd, DIOCGDINFO, &pinfo))
     {
       fprintf(stderr, "\r%s: ioctl failed, can't get disklabel for `%s': %s\n",
 	      argvzero, f->name, strerror(errno));
