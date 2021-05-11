--- third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc.orig	2021-04-30 09:00:21.722978000 +0000
+++ third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc	2021-04-30 09:00:54.473978000 +0000
@@ -202,6 +202,9 @@
   // a pointer |this|.
   av_context_->opaque = this;
 
+  // Initializing |lowres|
+  av_context_->lowres = 0;
+
   AVCodec* codec = avcodec_find_decoder(av_context_->codec_id);
   if (!codec) {
     // This is an indication that FFmpeg has not been initialized or it has not
