--- gst-libs/gst/video/video.h.orig	2012-09-08 10:03:46.000000000 +0200
+++ gst-libs/gst/video/video.h	2012-09-08 10:07:58.000000000 +0200
@@ -342,9 +342,9 @@
  */
 #define GST_VIDEO_CAPS_RGB8_PALETTED \
   "video/x-raw-rgb, bpp = (int)8, depth = (int)8, "                     \
-      "width = "GST_VIDEO_SIZE_RANGE" , "		                \
+      "width = " GST_VIDEO_SIZE_RANGE " , "		                \
       "height = " GST_VIDEO_SIZE_RANGE ", "                             \
-      "framerate = "GST_VIDEO_FPS_RANGE
+      "framerate = " GST_VIDEO_FPS_RANGE
 
 /**
  * GST_VIDEO_CAPS_YUV:
