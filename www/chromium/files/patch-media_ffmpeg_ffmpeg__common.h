--- media/ffmpeg/ffmpeg_common.h.orig	2017-04-19 19:06:35 UTC
+++ media/ffmpeg/ffmpeg_common.h
@@ -25,7 +25,7 @@ extern "C" {
 // Disable deprecated features which result in spammy compile warnings.  This
 // list of defines must mirror those in the 'defines' section of FFmpeg's
 // BUILD.gn file or the headers below will generate different structures!
-#define FF_API_CONVERGENCE_DURATION 0
+//#define FF_API_CONVERGENCE_DURATION 0
 // Upstream libavcodec/utils.c still uses the deprecated
 // av_dup_packet(), causing deprecation warnings.
 // The normal fix for such things is to disable the feature as below,
@@ -39,7 +39,6 @@ extern "C" {
 MSVC_PUSH_DISABLE_WARNING(4244);
 #include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
-#include <libavformat/internal.h>
 #include <libavformat/avio.h>
 #include <libavutil/avutil.h>
 #include <libavutil/imgutils.h>
