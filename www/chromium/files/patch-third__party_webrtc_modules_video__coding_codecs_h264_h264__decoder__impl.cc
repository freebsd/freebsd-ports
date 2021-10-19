--- third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc.orig	2021-09-24 04:28:18 UTC
+++ third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc
@@ -87,7 +87,10 @@ int H264DecoderImpl::AVGetBuffer2(AVCodecContext* cont
   int height = av_frame->height;
   // See `lowres`, if used the decoder scales the image by 1/2^(lowres). This
   // has implications on which resolutions are valid, but we don't use it.
+#if !defined(OS_FREEBSD)
+  // PR255687: disabled on FreeBSD to prevent crash with Microsoft Teams
   RTC_CHECK_EQ(context->lowres, 0);
+#endif
   // Adjust the `width` and `height` to values acceptable by the decoder.
   // Without this, FFmpeg may overflow the buffer. If modified, `width` and/or
   // `height` are larger than the actual image and the image has to be cropped
@@ -211,6 +214,9 @@ bool H264DecoderImpl::Configure(const Settings& settin
   // `get_buffer2` is called with the context, there `opaque` can be used to get
   // a pointer `this`.
   av_context_->opaque = this;
+
+  // Initializing |lowres|
+  av_context_->lowres = 0;
 
   const AVCodec* codec = avcodec_find_decoder(av_context_->codec_id);
   if (!codec) {
