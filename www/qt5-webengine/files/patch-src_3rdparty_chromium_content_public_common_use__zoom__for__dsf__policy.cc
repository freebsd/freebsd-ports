--- src/3rdparty/chromium/content/public/common/use_zoom_for_dsf_policy.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/public/common/use_zoom_for_dsf_policy.cc
@@ -25,7 +25,7 @@ bool IsUseZoomForDSFEnabledByDefault() {
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN) || defined(OS_ANDROID)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
