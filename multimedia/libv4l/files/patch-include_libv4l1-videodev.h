diff -ru v4l-utils-0.8.4.orig/lib/include/libv4l1-videodev.h v4l-utils-0.8.4/lib/include/libv4l1-videodev.h
--- include/libv4l1-videodev.h	2011-06-27 09:52:38.000000000 +0200
+++ include/libv4l1-videodev.h	2011-06-27 09:55:51.000000000 +0200
@@ -2,7 +2,14 @@
 #ifndef __LINUX_VIDEODEV_H
 #define __LINUX_VIDEODEV_H
 
+#ifdef linux
 #include <linux/ioctl.h>
+#endif
+
+#ifdef __FreeBSD__
+#include <sys/ioctl.h>
+#endif
+
 #include <stdint.h>
 
 #define VID_TYPE_CAPTURE	1	/* Can capture */
