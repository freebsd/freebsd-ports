--- libmpdemux/tv.h.orig	Sat Dec 28 23:57:39 2002
+++ libmpdemux/tv.h	Fri Aug 29 11:08:51 2003
@@ -24,9 +24,9 @@
 extern int tv_param_noaudio;
 extern int tv_param_immediate;
 extern int tv_param_audiorate;
+extern int tv_param_audio_id;
 #ifdef HAVE_TV_V4L
 extern int tv_param_amode;
-extern int tv_param_audio_id;
 extern int tv_param_volume;
 extern int tv_param_bass;
 extern int tv_param_treble;
