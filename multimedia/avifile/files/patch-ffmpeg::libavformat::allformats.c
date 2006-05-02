--- ffmpeg/libavformat/allformats.c.orig	Wed Jan 22 17:38:35 2003
+++ ffmpeg/libavformat/allformats.c	Mon Feb 27 20:12:55 2006
@@ -87,6 +87,7 @@
 #endif
 
     ffm_init();
+#undef CONFIG_VIDEO4LINUX
 #ifdef CONFIG_VIDEO4LINUX
     video_grab_init();
 #endif
