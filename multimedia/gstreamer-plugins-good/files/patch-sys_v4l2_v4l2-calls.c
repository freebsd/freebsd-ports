--- sys/v4l2/v4l2_calls.c.orig	2015-01-25 00:45:56.388735097 +0100
+++ sys/v4l2/v4l2_calls.c	2015-01-25 00:47:42.802727457 +0100
@@ -53,14 +53,6 @@
 
 #include "gst/gst-i18n-plugin.h"
 
-/* Those are ioctl calls */
-#ifndef V4L2_CID_HCENTER
-#define V4L2_CID_HCENTER V4L2_CID_HCENTER_DEPRECATED
-#endif
-#ifndef V4L2_CID_VCENTER
-#define V4L2_CID_VCENTER V4L2_CID_VCENTER_DEPRECATED
-#endif
-
 GST_DEBUG_CATEGORY_EXTERN (v4l2_debug);
 #define GST_CAT_DEFAULT v4l2_debug
 
@@ -294,8 +286,12 @@
         break;
       case V4L2_CID_HFLIP:
       case V4L2_CID_VFLIP:
+#ifdef V4L2_CID_HCENTER
       case V4L2_CID_HCENTER:
+#endif
+#ifdef V4L2_CID_VCENTER
       case V4L2_CID_VCENTER:
+#endif
 #ifdef V4L2_CID_PAN_RESET
       case V4L2_CID_PAN_RESET:
 #endif
