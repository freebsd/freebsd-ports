--- ffmpeg/_ffmpeg.pxi.orig	2013-10-28 16:04:02 UTC
+++ ffmpeg/_ffmpeg.pxi
@@ -35,6 +35,7 @@ cdef extern from "libavcodec/avcodec.h" 
         unsigned char **data
         int *linesize
         int64_t pts
+        int64_t pkt_pts;
         int repeat_pict
         int nb_samples
         int format
@@ -53,8 +54,6 @@ cdef extern from "libavcodec/avcodec.h" 
         int channels
         AVCodec *codec
         AVMediaType codec_type
-        int (*get_buffer)(AVCodecContext *c, AVFrame *pic)
-        void (*release_buffer)(AVCodecContext *c, AVFrame *pic)
         AVRational time_base
         AVSampleFormat sample_fmt
     struct AVPicture:
@@ -83,7 +82,7 @@ cdef extern from "libavcodec/avcodec.h" 
     ctypedef int (*lockmgr_t)(void **mutex, AVLockOp op)
     int av_lockmgr_register(lockmgr_t cb)
 
-    AVFrame *avcodec_alloc_frame() 
+    AVFrame *av_frame_alloc() 
     int avcodec_decode_video2(AVCodecContext *avctx, AVFrame *picture,
                          int *got_picture_ptr, AVPacket *avpkt)
     int avcodec_decode_audio4(AVCodecContext *avctx, AVFrame *frame, int
@@ -100,7 +99,7 @@ cdef extern from "libavcodec/avcodec.h" 
     int avcodec_default_get_buffer(AVCodecContext *s, AVFrame *pic)
     void avcodec_default_release_buffer(AVCodecContext *s, AVFrame *pic)
 
-    void avcodec_get_frame_defaults(AVFrame *)
+    void av_frame_unref(AVFrame *)
 
 cdef extern from "libavresample/avresample.h" nogil:
     struct ResampleContext:
