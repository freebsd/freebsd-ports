--- ui/base/resource/resource_bundle.cc.orig	2026-10-31 12:09:36 UTC
+++ ui/base/resource/resource_bundle.cc
@@ -1004,7 +1004,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ResourceScaleFactor ResourceBundle::GetMaxResourceScaleFactor() const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return max_scale_factor_;
 #else
   return GetMaxSupportedResourceScaleFactor();
