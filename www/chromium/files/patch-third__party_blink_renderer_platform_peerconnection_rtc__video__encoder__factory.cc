--- third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc.orig	2025-10-30 15:44:36 UTC
+++ third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc
@@ -36,7 +36,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables H.264 CBP encode acceleration.
 BASE_FEATURE(kPlatformH264CbpEncoding,
 #if BUILDFLAG(IS_WIN)
@@ -327,7 +327,7 @@ SupportedFormats GetSupportedFormatsInternal(
       supported_formats.profiles.push_back(profile.profile);
       supported_formats.sdp_formats.push_back(std::move(*format));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       const bool kShouldAddH264Cbp =
           base::FeatureList::IsEnabled(kPlatformH264CbpEncoding) &&
           profile.profile == media::VideoCodecProfile::H264PROFILE_BASELINE;
