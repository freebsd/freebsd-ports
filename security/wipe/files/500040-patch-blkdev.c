--- blkdev.c.orig   Sun Aug  3 16:07:29 2003
+++ blkdev.c        Sat Mar  5 00:23:40 2005
@@ -128,6 +128,10 @@
   int code;
 
 #ifdef BSD_BLKDEV
+  struct partinfo {
+    struct disklabel *disklab;
+    struct partition *part;
+  };
   struct partinfo pinfo;
 #endif
 
@@ -160,7 +164,7 @@
     }
 
 #ifdef BSD_BLKDEV
-  if (ioctl(f->fd, DIOCGPART, &pinfo))
+  if (ioctl(f->fd, DIOCGDINFO, &pinfo))
     {
       fprintf(stderr, "\r%s: ioctl failed, can't get disklabel for `%s': %s\n",
 	      argvzero, f->name, strerror(errno));
