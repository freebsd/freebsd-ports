--- ./kopete/libkopete/avdevice/videodevice.h.orig	2009-03-18 13:00:00.000000000 +0300
+++ ./kopete/libkopete/avdevice/videodevice.h	2010-03-28 14:25:38.820037067 +0400
@@ -62,6 +62,13 @@
 
 #endif // __linux__
 
+#if defined(__FreeBSD__) && defined(ENABLE_AV)
+#include <linux/videodev.h>
+#ifdef HAVE_LIBV4L2
+#include <libv4l2.h>
+#endif // HAVE_LIBV4L2
+#endif
+
 #include <qstring.h>
 #include <qfile.h>
 #include <qimage.h>
@@ -80,7 +87,7 @@
 typedef enum
 {
 	VIDEODEV_DRIVER_NONE
-#if defined( __linux__) && defined(ENABLE_AV)
+#if (defined( __linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
         ,
 	VIDEODEV_DRIVER_V4L
 #ifdef V4L2_CAP_VIDEO_CAPTURE
@@ -294,7 +301,7 @@
 	int descriptor;
 
 //protected:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined( __linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 	struct v4l2_capability V4L2_capabilities;
 	struct v4l2_cropcap cropcap;
