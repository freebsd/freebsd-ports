--- media/webrtc/helpers_unittests.cc.orig	2024-03-22 14:16:19 UTC
+++ media/webrtc/helpers_unittests.cc
@@ -40,7 +40,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest, CheckDefau
   EXPECT_TRUE(config.echo_canceller.enabled);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(config.gain_controller1.enabled);
   EXPECT_TRUE(config.gain_controller2.enabled);
 #elif BUILDFLAG(IS_CASTOS) || BUILDFLAG(IS_CAST_ANDROID)
@@ -58,7 +58,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest, CheckDefau
             webrtc::AudioProcessing::Config::NoiseSuppression::kHigh);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(config.transient_suppression.enabled);
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   // Android and iOS use echo cancellation optimized for mobiles, and does not
@@ -79,7 +79,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest,
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      InputVolumeAdjustmentEnabledWithAgc2) {
   ::base::test::ScopedFeatureList feature_list;
@@ -95,7 +95,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      CanDisableInputVolumeAdjustmentWithAgc2) {
   ::base::test::ScopedFeatureList feature_list;
@@ -112,7 +112,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      OnlyOneInputVolumeControllerEnabledOnDesktopPlatforms) {
   auto config = CreateApmGetConfig(
@@ -197,7 +197,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest, ToggleTran
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) ||               \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
     // Transient suppression is not supported (nor useful) on mobile platforms.
     EXPECT_FALSE(config.transient_suppression.enabled);
 #else
