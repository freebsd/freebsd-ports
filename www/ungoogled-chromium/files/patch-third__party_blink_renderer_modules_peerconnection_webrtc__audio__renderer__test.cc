--- third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc.orig	2024-07-31 14:19:23 UTC
+++ third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc
@@ -301,7 +301,7 @@ TEST_F(WebRtcAudioRendererTest, DISABLED_VerifySinkPar
   SetupRenderer(kDefaultOutputDeviceId);
   renderer_proxy_->Start();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   static const int kExpectedBufferSize = kHardwareSampleRate / 100;
 #elif BUILDFLAG(IS_ANDROID)
   static const int kExpectedBufferSize = 2 * kHardwareSampleRate / 100;
