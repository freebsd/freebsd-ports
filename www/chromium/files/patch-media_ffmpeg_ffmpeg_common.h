--- media/ffmpeg/ffmpeg_common.h.orig	2018-07-20 02:33:15.643297000 +0200
+++ media/ffmpeg/ffmpeg_common.h	2018-07-20 02:34:16.943706000 +0200
@@ -28,9 +28,6 @@
 MSVC_PUSH_DISABLE_WARNING(4244);
 #include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
-#if !BUILDFLAG(USE_SYSTEM_FFMPEG)
-#include <libavformat/internal.h>
-#endif  // !BUILDFLAG(USE_SYSTEM_FFMPEG)
 #include <libavformat/avio.h>
 #include <libavutil/avutil.h>
 #include <libavutil/imgutils.h>
@@ -41,6 +38,8 @@
 }  // extern "C"
 
 namespace media {
+
+constexpr int64_t kNoFFmpegTimestamp = static_cast<int64_t>(AV_NOPTS_VALUE);
 
 class AudioDecoderConfig;
 class EncryptionScheme;
