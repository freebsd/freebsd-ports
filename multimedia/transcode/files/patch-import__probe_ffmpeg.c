--- import/probe_ffmpeg.c.orig	2011-11-19 16:50:27 UTC
+++ import/probe_ffmpeg.c
@@ -120,7 +120,7 @@
 
     translate_info(lavf_dmx_context, ipipe->probe_info);
 
-    av_close_input_file(lavf_dmx_context);
+    avformat_close_input(lavf_dmx_context);
     return;
 }
 
