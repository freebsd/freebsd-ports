--- content/renderer/media/webrtc/webrtc_audio_renderer_unittest.cc.orig	2019-10-21 19:06:32 UTC
+++ content/renderer/media/webrtc/webrtc_audio_renderer_unittest.cc
@@ -244,7 +244,7 @@ TEST_F(WebRtcAudioRendererTest, MultipleRenderers) {
 TEST_F(WebRtcAudioRendererTest, VerifySinkParameters) {
   SetupRenderer(kDefaultOutputDeviceId);
   renderer_proxy_->Start();
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   static const int kExpectedBufferSize = kHardwareSampleRate / 100;
 #elif defined(OS_ANDROID)
   static const int kExpectedBufferSize = 2 * kHardwareSampleRate / 100;
