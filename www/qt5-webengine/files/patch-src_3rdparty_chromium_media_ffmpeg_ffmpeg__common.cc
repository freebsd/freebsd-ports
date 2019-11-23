--- src/3rdparty/chromium/media/ffmpeg/ffmpeg_common.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/media/ffmpeg/ffmpeg_common.cc
@@ -686,10 +686,6 @@ ChannelLayout ChannelLayoutToChromeChannelLayout(int64
   }
 }
 
-#if !defined(ARCH_CPU_LITTLE_ENDIAN)
-#error The code below assumes little-endianness.
-#endif
-
 VideoPixelFormat AVPixelFormatToVideoPixelFormat(AVPixelFormat pixel_format) {
   // The YUVJ alternatives are FFmpeg's (deprecated, but still in use) way to
   // specify a pixel format and full range color combination.
