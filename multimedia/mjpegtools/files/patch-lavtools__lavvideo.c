--- lavtools/lavvideo.c.orig
+++ lavtools/lavvideo.c
@@ -49,6 +49,7 @@
 #include <sys/stat.h>
 #include <sys/ioctl.h>
 
+#ifdef __linux
 #include <linux/types.h>
 /* Because of some really cool feature in video4linux1, also known as
  * 'not including sys/types.h and sys/time.h', we had to include it
@@ -63,6 +64,7 @@
  * errors here, check your linux/time.h && sys/time.h header setup.
  */
 #define _LINUX_TIME_H
+#endif
 #include <linux/videodev.h>
 
 #include <videodev_mjpeg.h>
