--- libavformat/avformat.h.orig	Wed Jan  1 21:03:56 2003
+++ libavformat/avformat.h	Wed Jan  1 21:04:02 2003
@@ -329,7 +329,7 @@
 int video_grab_init(void);
 int audio_init(void);
 
-extern const char *v4l_device;
+extern const char *video_device;
 extern const char *audio_device;
 
 #ifdef HAVE_AV_CONFIG_H
