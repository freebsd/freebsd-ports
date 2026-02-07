--- media/webrtc/helpers_unittests.cc.orig	2025-12-06 13:30:52 UTC
+++ media/webrtc/helpers_unittests.cc
@@ -37,7 +37,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest, CheckDefau
   EXPECT_TRUE(config.echo_canceller.enabled);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(config.gain_controller1.enabled);
   EXPECT_TRUE(config.gain_controller2.enabled);
 #elif BUILDFLAG(IS_CASTOS) || BUILDFLAG(IS_CAST_ANDROID)
@@ -63,7 +63,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest,
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      InputVolumeAdjustmentEnabledWithAgc2) {
   ::base::test::ScopedFeatureList feature_list;
@@ -79,7 +79,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      CanDisableInputVolumeAdjustmentWithAgc2) {
   ::base::test::ScopedFeatureList feature_list;
@@ -96,7 +96,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      OnlyOneInputVolumeControllerEnabledOnDesktopPlatforms) {
   auto config = CreateApmGetConfig(
