--- content/renderer/media/webrtc/webrtc_audio_renderer_unittest.cc.orig	2019-03-17 17:29:28 UTC
+++ content/renderer/media/webrtc/webrtc_audio_renderer_unittest.cc
@@ -203,7 +203,7 @@ TEST_F(WebRtcAudioRendererTest, MultipleRenderers) {
 TEST_F(WebRtcAudioRendererTest, VerifySinkParameters) {
   SetupRenderer(kDefaultOutputDeviceId);
   renderer_proxy_->Start();
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   static const int kExpectedBufferSize = kHardwareSampleRate / 100;
 #elif defined(OS_ANDROID)
   static const int kExpectedBufferSize = 2 * kHardwareSampleRate / 100;
