--- ext/ffmpeg/gstffmpegcodecmap.c.orig	Fri Feb  6 15:29:09 2004
+++ ext/ffmpeg/gstffmpegcodecmap.c	Fri Feb  6 15:40:14 2004
@@ -44,13 +44,13 @@
 	"width",     G_TYPE_INT,   context->width,	      	\
 	"height",    G_TYPE_INT,   context->height,	  	\
 	"framerate", G_TYPE_DOUBLE, 1. * context->frame_rate /  \
-				   context->frame_rate_base,    \
+				   context->frame_rate_base ,    \
 	##props, NULL)	  					\
     :	  							\
     gst_caps_new_simple (mimetype,			      	\
 	"width",     GST_TYPE_INT_RANGE, 16, 4096,      	\
 	"height",    GST_TYPE_INT_RANGE, 16, 4096,	      	\
-	"framerate", GST_TYPE_DOUBLE_RANGE, 0., G_MAXDOUBLE,	\
+	"framerate", GST_TYPE_DOUBLE_RANGE, 0., G_MAXDOUBLE ,	\
 	##props, NULL)
 
 /* same for audio - now with channels/sample rate
@@ -60,10 +60,10 @@
     (context != NULL) ?					      	\
     gst_caps_new_simple (mimetype,	      			\
 	"rate", G_TYPE_INT, context->sample_rate,		\
-	"channels", G_TYPE_INT, context->channels,		\
+	"channels", G_TYPE_INT, context->channels ,		\
 	##props, NULL)						\
     :								\
-    gst_caps_new_simple (mimetype,	      			\
+    gst_caps_new_simple (mimetype ,	      			\
 	##props, NULL)
 
 /* Convert a FFMPEG codec ID and optional AVCodecContext
