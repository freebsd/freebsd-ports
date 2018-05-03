mediaenc_ffmpeg.cpp:215:18: error: use of undeclared identifier 'CODEC_FLAG_GLOBAL_HEADER'
            c->flags |= CODEC_FLAG_GLOBAL_HEADER;
                        ^

--- src/mediaenc_ffmpeg.cpp.orig	2015-10-04 13:18:58 UTC
+++ src/mediaenc_ffmpeg.cpp
@@ -48,6 +48,9 @@ extern "C" {
 #define av_frame_free avcodec_free_frame
 #endif
 
+#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(56, 34, 1)
+#define AV_CODEC_FLAG_GLOBAL_HEADER CODEC_FLAG_GLOBAL_HEADER
+#endif
 
 wxFfmpegMediaEncoder::wxFfmpegMediaEncoder(int threadCount) {
 	m_threadCount = threadCount;
@@ -212,7 +215,7 @@ bool wxFfmpegMediaEncoder::addAudioStream(int codecId)
 	c->time_base = (AVRational){ 1, c->sample_rate };
 	// some formats want stream headers to be separate
 	if(m_outputCtx->oformat->flags & AVFMT_GLOBALHEADER)
-	    c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+	    c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
 	
 	return true;
 }
