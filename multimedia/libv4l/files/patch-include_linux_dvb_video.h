--- include/linux/dvb/video.h.orig	2015-01-10 15:05:58.438363362 +0100
+++ include/linux/dvb/video.h	2015-01-10 15:06:25.350361374 +0100
@@ -133,7 +133,7 @@
 #define VIDEO_EVENT_FRAME_RATE_CHANGED	2
 #define VIDEO_EVENT_DECODER_STOPPED 	3
 #define VIDEO_EVENT_VSYNC 		4
-	__kernel_time_t timestamp;
+	struct timespec timestamp;
 	union {
 		video_size_t size;
 		unsigned int frame_rate;	/* in frames per 1000sec */
