--- third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc.orig	2021-05-10 18:48:00 UTC
+++ third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc
@@ -77,7 +77,8 @@ int H264DecoderImpl::AVGetBuffer2(AVCodecContext* cont
   int height = av_frame->height;
   // See |lowres|, if used the decoder scales the image by 1/2^(lowres). This
   // has implications on which resolutions are valid, but we don't use it.
-  RTC_CHECK_EQ(context->lowres, 0);
+  // PR255687: disabled to prevent crash with Microsoft Teams
+  // RTC_CHECK_EQ(context->lowres, 0);
   // Adjust the |width| and |height| to values acceptable by the decoder.
   // Without this, FFmpeg may overflow the buffer. If modified, |width| and/or
   // |height| are larger than the actual image and the image has to be cropped
@@ -201,6 +202,9 @@ int32_t H264DecoderImpl::InitDecode(const VideoCodec* 
   // |get_buffer2| is called with the context, there |opaque| can be used to get
   // a pointer |this|.
   av_context_->opaque = this;
+
+  // Initializing |lowres|
+  av_context_->lowres = 0;
 
   AVCodec* codec = avcodec_find_decoder(av_context_->codec_id);
   if (!codec) {
