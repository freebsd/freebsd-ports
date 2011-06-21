--- gst-libs/ext/ffmpeg/libavcodec/x86/dsputil_mmx.c.orig	2011-06-21 13:50:43.000000000 +0200
+++ gst-libs/ext/ffmpeg/libavcodec/x86/dsputil_mmx.c	2011-06-21 13:51:01.000000000 +0200
@@ -606,7 +606,7 @@ static void add_hfyu_median_prediction_c
     __asm__ volatile(
         "mov    %7, %3 \n"
         "1: \n"
-        "movzx (%3,%4), %2 \n"
+        "movzbl (%3,%4), %2 \n"
         "mov    %2, %k3 \n"
         "sub   %b1, %b3 \n"
         "add   %b0, %b3 \n"
