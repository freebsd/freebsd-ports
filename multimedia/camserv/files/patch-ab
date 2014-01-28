--- camserv/video_fbsd_bttv.c.orig	2002-09-16 07:01:56.000000000 +0900
+++ camserv/video_fbsd_bttv.c	2014-01-04 04:56:21.000000000 +0900
@@ -27,8 +27,9 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/mman.h>
-#include <machine/ioctl_bt848.h>
-#include <machine/ioctl_meteor.h>
+#include <sys/types.h>
+#include <dev/bktr/ioctl_bt848.h>
+#include <dev/bktr/ioctl_meteor.h>
 #include <signal.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
@@ -642,7 +643,7 @@
     return 0;
 
   totmean = camserv_get_pic_mean( width, height, picbuf, 1, 0, 0, 
-				  width, height );
+				  width-1, height-1 );
   if( totmean < (256 / 2) - 10 || totmean > (256 / 2) + 10 ) {
     newbright = fbttv_dev->brightness;
     if( totmean > (256 / 2) + 10 ){
