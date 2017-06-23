--- media/ffmpeg/ffmpeg_common.h.orig	2017-06-05 19:03:08 UTC
+++ media/ffmpeg/ffmpeg_common.h
@@ -23,10 +23,12 @@
 
 // Include FFmpeg header files.
 extern "C" {
+#if !defined(USE_SYSTEM_FFMPEG)
 // Disable deprecated features which result in spammy compile warnings.  This
 // list of defines must mirror those in the 'defines' section of FFmpeg's
 // BUILD.gn file or the headers below will generate different structures!
 #define FF_API_CONVERGENCE_DURATION 0
+#endif // !defined(USE_SYSTEM_FFMPEG)
 // Upstream libavcodec/utils.c still uses the deprecated
 // av_dup_packet(), causing deprecation warnings.
 // The normal fix for such things is to disable the feature as below,
@@ -40,7 +42,9 @@ extern "C" {
 MSVC_PUSH_DISABLE_WARNING(4244);
 #include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
+#if !defined(USE_SYSTEM_FFMPEG)
 #include <libavformat/internal.h>
+#endif // !defined(USE_SYSTEM_FFMPEG)
 #include <libavformat/avio.h>
 #include <libavutil/avutil.h>
 #include <libavutil/imgutils.h>
