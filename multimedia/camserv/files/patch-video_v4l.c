--- camserv/video_v4l.c.orig	2002-09-15 15:01:56.000000000 -0700
+++ camserv/video_v4l.c	2011-05-19 22:05:38.000000000 -0700
@@ -304,7 +304,7 @@
 
 static
 int setup_video_channel( Video_V4L *v4l_dev, CamConfig *ccfg ){
-  ulong frequency;
+  unsigned long frequency;
   int use_channel;
   int cfg_channel, cfg_frequency, cfg_color, cfg_hue, cfg_contrast,
       cfg_brightness, cfg_whiteness, cfg_norm;
