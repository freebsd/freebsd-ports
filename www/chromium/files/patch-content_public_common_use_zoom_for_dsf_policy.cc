--- content/public/common/use_zoom_for_dsf_policy.cc.orig	2019-01-09 12:03:15.666391000 +0100
+++ content/public/common/use_zoom_for_dsf_policy.cc	2019-01-09 12:03:35.744606000 +0100
@@ -25,7 +25,7 @@
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN) || defined(OS_ANDROID)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
