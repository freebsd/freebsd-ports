--- ffmpeg/libavformat/allformats.c.orig	Wed Jan 22 17:38:35 2003
+++ ffmpeg/libavformat/allformats.c	Wed Jan 22 17:37:03 2003
@@ -55,6 +55,7 @@
 #ifndef CONFIG_WIN32
     ffm_init();
 #endif
+#undef CONFIG_VIDEO4LINUX
 #ifdef CONFIG_VIDEO4LINUX
     video_grab_init();
 #endif
