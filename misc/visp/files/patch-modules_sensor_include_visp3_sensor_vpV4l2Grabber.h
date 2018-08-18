https://github.com/lagadic/visp/issues/422

--- modules/sensor/include/visp3/sensor/vpV4l2Grabber.h.orig	2018-08-18 07:45:47 UTC
+++ modules/sensor/include/visp3/sensor/vpV4l2Grabber.h
@@ -50,8 +50,8 @@
 #ifdef VISP_HAVE_V4L2
 
 #include <libv4l2.h> // Video For Linux Two interface
-#include <linux/kernel.h>
-#include <linux/types.h>
+//#include <linux/kernel.h>
+//#include <linux/types.h>
 #include <linux/videodev2.h> // Video For Linux Two interface
 
 #include <visp3/core/vpFrameGrabber.h>
