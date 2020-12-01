--- third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc.orig	2020-11-13 06:36:48 UTC
+++ third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc
@@ -272,7 +272,7 @@ TEST_F(MAYBE_WebRtcAudioRendererTest, MultipleRenderer
 TEST_F(MAYBE_WebRtcAudioRendererTest, VerifySinkParameters) {
   SetupRenderer(kDefaultOutputDeviceId);
   renderer_proxy_->Start();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   static const int kExpectedBufferSize = kHardwareSampleRate / 100;
 #elif defined(OS_ANDROID)
