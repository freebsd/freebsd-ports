--- libav/avformat.h	Mon Jul  8 04:38:40 2002
+++ libav/avformat.h	Sun Jul 14 15:22:58 2002
@@ -284,5 +284,5 @@
 int video_grab_init(void);
 int audio_init(void);
 
-extern const char *v4l_device;
+extern const char *video_device;
 extern const char *audio_device;
