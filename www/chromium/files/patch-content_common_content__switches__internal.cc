--- content/common/content_switches_internal.cc.orig	2017-12-15 02:04:17.000000000 +0100
+++ content/common/content_switches_internal.cc	2017-12-24 13:18:56.301831000 +0100
@@ -41,7 +41,7 @@
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
