--- third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc.orig	2020-07-13 10:01:57 UTC
+++ third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc
@@ -243,7 +243,7 @@ TEST_F(WebRtcAudioRendererTest, MultipleRenderers) {
 TEST_F(WebRtcAudioRendererTest, VerifySinkParameters) {
   SetupRenderer(kDefaultOutputDeviceId);
   renderer_proxy_->Start();
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   static const int kExpectedBufferSize = kHardwareSampleRate / 100;
 #elif defined(OS_ANDROID)
   static const int kExpectedBufferSize = 2 * kHardwareSampleRate / 100;
