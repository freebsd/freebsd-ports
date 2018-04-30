--- media/filters/ffmpeg_video_decoder.cc.orig	2018-04-28 14:12:48.579561000 +0200
+++ media/filters/ffmpeg_video_decoder.cc	2018-04-28 14:16:02.028730000 +0200
@@ -417,12 +417,11 @@
   codec_context_->thread_type =
       FF_THREAD_SLICE | (low_delay ? 0 : FF_THREAD_FRAME);
   codec_context_->opaque = this;
-  codec_context_->flags |= CODEC_FLAG_EMU_EDGE;
   codec_context_->get_buffer2 = GetVideoBufferImpl;
   codec_context_->refcounted_frames = 1;
 
   if (decode_nalus_)
-    codec_context_->flags2 |= CODEC_FLAG2_CHUNKS;
+    codec_context_->flags2 |= AV_CODEC_FLAG2_CHUNKS;
 
   AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
   if (!codec || avcodec_open2(codec_context_.get(), codec, NULL) < 0) {
