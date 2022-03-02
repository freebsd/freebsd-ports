--- content/public/common/use_zoom_for_dsf_policy.cc.orig	2022-02-28 16:54:41 UTC
+++ content/public/common/use_zoom_for_dsf_policy.cc
@@ -26,7 +26,7 @@ const base::Feature kUseZoomForDsfEnabledByDefault{
 
 bool IsUseZoomForDSFEnabledByDefault() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return true;
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
