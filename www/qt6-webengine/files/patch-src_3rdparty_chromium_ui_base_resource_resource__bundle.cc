--- src/3rdparty/chromium/ui/base/resource/resource_bundle.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/resource/resource_bundle.cc
@@ -924,7 +924,7 @@ ResourceScaleFactor ResourceBundle::GetMaxResourceScal
 }
 
 ResourceScaleFactor ResourceBundle::GetMaxResourceScaleFactor() const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return max_scale_factor_;
 #else
   return GetMaxSupportedResourceScaleFactor();
