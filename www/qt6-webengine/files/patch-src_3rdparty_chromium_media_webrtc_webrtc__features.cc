--- src/3rdparty/chromium/media/webrtc/webrtc_features.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/webrtc/webrtc_features.cc
@@ -9,7 +9,7 @@ namespace {
 
 namespace features {
 namespace {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr base::FeatureState kWebRtcHybridAgcState =
     base::FEATURE_ENABLED_BY_DEFAULT;
 #else
