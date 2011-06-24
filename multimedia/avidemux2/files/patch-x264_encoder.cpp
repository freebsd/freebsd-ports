--- plugins/ADM_videoEncoder/ADM_vidEnc_x264/encoder.cpp.orig	2011-06-24 13:04:17.000000000 +0200
+++ plugins/ADM_videoEncoder/ADM_vidEnc_x264/encoder.cpp	2011-06-24 13:05:22.000000000 +0200
@@ -488,8 +488,10 @@ void x264Encoder::printParam(x264_param_
 	printf("[x264] analyse.b_transform_8x8 = %d\n", x264Param->analyse.b_transform_8x8);
 	printf("[x264] analyse.inter = %d\n", x264Param->analyse.inter);
 	printf("[x264] b_cabac = %d\n", x264Param->b_cabac);
-#if X264_BUILD > 101
+#if X264_BUILD > 101 && X264_BUILD < 115
 	printf("[x264] i_open_gop = %d\n", x264Param->i_open_gop);
+#else X264_BUILD > 114
+	printf("[x264] b_open_gop = %d\n", x264Param->b_open_gop);
 #endif
 	printf("[x264] b_interlaced = %d\n", x264Param->b_interlaced);
 #if X264_BUILD > 88
