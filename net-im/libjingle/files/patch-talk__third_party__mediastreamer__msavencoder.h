--- talk/third_party/mediastreamer/msavencoder.h.orig	Thu May 11 01:05:51 2006
+++ talk/third_party/mediastreamer/msavencoder.h	Thu May 11 01:06:18 2006
@@ -44,6 +44,7 @@
 	gint av_opened;
 	MSBuffer *comp_buf;
 	MSBuffer *yuv_buf;
+	MSMessage *outm;
 };
 
 typedef struct _MSAVEncoder MSAVEncoder;
