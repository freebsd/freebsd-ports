--- src/3rdparty/chromium/ui/base/resource/resource_bundle.cc.orig	2017-01-26 00:49:31 UTC
+++ src/3rdparty/chromium/ui/base/resource/resource_bundle.cc
@@ -651,7 +651,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -711,7 +711,7 @@ void ResourceBundle::InitSharedInstance(
     supported_scale_factors.push_back(SCALE_FACTOR_100P);
   }
 #elif defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
   ui::SetSupportedScaleFactors(supported_scale_factors);
