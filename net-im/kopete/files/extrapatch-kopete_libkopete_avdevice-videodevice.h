--- kopete/libkopete/avdevice/videodevice.h	2009-01-06 19:45:45.000000000 +0100
+++ kopete/libkopete/avdevice/videodevice.h	2009-01-06 19:47:07.000000000 +0100
@@ -33,9 +33,12 @@
 #include <unistd.h>
 #include <signal.h>
 
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 
+#if defined(__linux__)
 #include <asm/types.h>
+#endif
+
 #undef __STRICT_ANSI__
 #ifndef __u64 //required by videodev.h
 #define __u64 unsigned long long
@@ -50,8 +53,11 @@
 #define pgoff_t unsigned long
 #endif
 
+#if defined(__linux__)
 #include <linux/fs.h>
 #include <linux/kernel.h>
+#endif
+
 #include <linux/videodev.h>
 #define VIDEO_MODE_PAL_Nc  3
 #define VIDEO_MODE_PAL_M   4
@@ -80,8 +86,8 @@
 typedef enum
 {
 	VIDEODEV_DRIVER_NONE
-#if defined( __linux__) && defined(ENABLE_AV)
-        ,
+#if (defined( __linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
+		,
 	VIDEODEV_DRIVER_V4L
 #ifdef V4L2_CAP_VIDEO_CAPTURE
         ,
@@ -276,7 +282,7 @@
 	int descriptor;
 
 //protected:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 	struct v4l2_capability V4L2_capabilities;
 	struct v4l2_cropcap cropcap;
