--- libmpdemux/tv.c.orig	Mon Mar 10 17:00:39 2003
+++ libmpdemux/tv.c	Fri Aug 29 11:08:51 2003
@@ -53,9 +53,9 @@
 char *tv_param_outfmt = "yv12";
 float tv_param_fps = -1.0;
 char **tv_param_channels = NULL;
+int tv_param_audio_id = 0;
 #ifdef HAVE_TV_V4L
 int tv_param_amode = -1;
-int tv_param_audio_id = 0;
 int tv_param_volume = 60000;
 int tv_param_bass = -1;
 int tv_param_treble = -1;
