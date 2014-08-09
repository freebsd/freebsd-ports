--- plugins/input_uvc/uvcvideo.h.orig	2008-06-16 14:23:51.000000000 +0300
+++ plugins/input_uvc/uvcvideo.h	2013-08-24 04:50:23.000000000 +0300
@@ -25,7 +25,7 @@
 #ifndef _USB_VIDEO_H_
 #define _USB_VIDEO_H_
 
-#include <linux/kernel.h>
+#include <sys/types.h>
 #include <linux/videodev.h>
 
 /* Compatibility */
