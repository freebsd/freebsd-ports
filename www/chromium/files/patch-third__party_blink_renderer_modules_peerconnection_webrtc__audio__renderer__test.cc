--- third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc.orig	2021-09-14 01:52:02 UTC
+++ third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc
@@ -289,7 +289,7 @@ TEST_F(MAYBE_WebRtcAudioRendererTest, DISABLED_Multipl
 TEST_F(MAYBE_WebRtcAudioRendererTest, DISABLED_VerifySinkParameters) {
   SetupRenderer(kDefaultOutputDeviceId);
   renderer_proxy_->Start();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   static const int kExpectedBufferSize = kHardwareSampleRate / 100;
 #elif defined(OS_ANDROID)
