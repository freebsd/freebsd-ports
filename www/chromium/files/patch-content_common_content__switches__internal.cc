--- content/common/content_switches_internal.cc.orig	2017-06-05 19:03:07 UTC
+++ content/common/content_switches_internal.cc
@@ -27,7 +27,7 @@ const base::Feature kUseZoomForDsfEnabledByDefault {
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
