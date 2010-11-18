--- Source/video_ffmpeg.h.orig	2005-03-08 01:23:58.000000000 +0100
+++ Source/video_ffmpeg.h	2010-08-15 08:11:13.000000000 +0200
@@ -24,7 +24,7 @@
     PIX_FMT_BGR24,     ///< Packed pixel, 3 bytes per pixel, BGRBGR...
     PIX_FMT_YUV422P,   ///< Planar YUV 4:2:2 (1 Cr & Cb sample per 2x1 Y samples)
     PIX_FMT_YUV444P,   ///< Planar YUV 4:4:4 (1 Cr & Cb sample per 1x1 Y samples)
-    PIX_FMT_RGBA32,    ///< Packed pixel, 4 bytes per pixel, BGRABGRA..., stored in cpu endianness
+    PIX_FMT_RGB32,     ///< Packed pixel, 4 bytes per pixel, BGRABGRA..., stored in cpu endianness
     PIX_FMT_YUV410P,   ///< Planar YUV 4:1:0 (1 Cr & Cb sample per 4x4 Y samples)
     PIX_FMT_YUV411P,   ///< Planar YUV 4:1:1 (1 Cr & Cb sample per 4x1 Y samples)
     PIX_FMT_RGB565,    ///< always stored in cpu endianness 
