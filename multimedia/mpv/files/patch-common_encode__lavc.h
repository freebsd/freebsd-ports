--- common/encode_lavc.h.orig	2016-04-11 17:10:54 UTC
+++ common/encode_lavc.h
@@ -46,8 +46,14 @@ struct encode_lavc_context {
 
     float vo_fps;
 
-    // these are processed from the options
+    // FFmpeg contexts.
     AVFormatContext *avc;
+    AVStream *vst;
+    AVStream *ast;
+    AVCodecContext *vcc;
+    AVCodecContext *acc;
+
+    // these are processed from the options
     AVRational timebase;
     AVCodec *vc;
     AVCodec *ac;
@@ -88,26 +94,31 @@ struct encode_lavc_context {
 };
 
 // interface for vo/ao drivers
-AVStream *encode_lavc_alloc_stream(struct encode_lavc_context *ctx, enum AVMediaType mt);
-void encode_lavc_write_stats(struct encode_lavc_context *ctx, AVStream *stream);
-int encode_lavc_write_frame(struct encode_lavc_context *ctx, AVPacket *packet);
+int encode_lavc_alloc_stream(struct encode_lavc_context *ctx,
+                             enum AVMediaType mt, AVStream **stream_out,
+                             AVCodecContext **codec_out);
+void encode_lavc_write_stats(struct encode_lavc_context *ctx,
+                             AVCodecContext *stream);
+int encode_lavc_write_frame(struct encode_lavc_context *ctx, AVStream *stream,
+                            AVPacket *packet);
 int encode_lavc_supports_pixfmt(struct encode_lavc_context *ctx, enum AVPixelFormat format);
-AVCodec *encode_lavc_get_codec(struct encode_lavc_context *ctx, AVStream *stream);
-int encode_lavc_open_codec(struct encode_lavc_context *ctx, AVStream *stream);
+int encode_lavc_open_codec(struct encode_lavc_context *ctx,
+                           AVCodecContext *codec);
 int encode_lavc_available(struct encode_lavc_context *ctx);
 int encode_lavc_timesyncfailed(struct encode_lavc_context *ctx);
 int encode_lavc_start(struct encode_lavc_context *ctx); // returns 1 on success
 int encode_lavc_oformat_flags(struct encode_lavc_context *ctx);
-double encode_lavc_getoffset(struct encode_lavc_context *ctx, AVStream *stream);
+double encode_lavc_getoffset(struct encode_lavc_context *ctx,
+                             AVCodecContext *codec);
 void encode_lavc_fail(struct encode_lavc_context *ctx, const char *format, ...); // report failure of encoding
 
 bool encode_lavc_set_csp(struct encode_lavc_context *ctx,
-                         AVStream *stream, enum mp_csp csp);
+                         AVCodecContext *codec, enum mp_csp csp);
 bool encode_lavc_set_csp_levels(struct encode_lavc_context *ctx,
-                                AVStream *stream, enum mp_csp_levels lev);
+                                AVCodecContext *codec, enum mp_csp_levels lev);
 enum mp_csp encode_lavc_get_csp(struct encode_lavc_context *ctx,
-                                AVStream *stream);
+                                AVCodecContext *codec);
 enum mp_csp_levels encode_lavc_get_csp_levels(struct encode_lavc_context *ctx,
-                                              AVStream *stream);
+                                              AVCodecContext *codec);
 
 #endif
