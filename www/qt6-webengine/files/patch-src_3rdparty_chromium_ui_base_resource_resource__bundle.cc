--- src/3rdparty/chromium/ui/base/resource/resource_bundle.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/base/resource/resource_bundle.cc
@@ -882,7 +882,7 @@ ResourceScaleFactor ResourceBundle::GetMaxResourceScal
 }
 
 ResourceScaleFactor ResourceBundle::GetMaxResourceScaleFactor() const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedResourceScaleFactors().back();
