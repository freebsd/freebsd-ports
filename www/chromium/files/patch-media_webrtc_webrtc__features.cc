--- media/webrtc/webrtc_features.cc.orig	2021-12-16 15:13:21 UTC
+++ media/webrtc/webrtc_features.cc
@@ -9,7 +9,7 @@
 
 namespace features {
 namespace {
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 constexpr base::FeatureState kWebRtcHybridAgcState =
     base::FEATURE_ENABLED_BY_DEFAULT;
 #else
