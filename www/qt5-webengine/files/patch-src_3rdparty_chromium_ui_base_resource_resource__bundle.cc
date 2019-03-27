--- src/3rdparty/chromium/ui/base/resource/resource_bundle.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/base/resource/resource_bundle.cc
@@ -720,7 +720,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -766,7 +766,7 @@ void ResourceBundle::InitSharedInstance(Delegate* dele
   // On platforms other than iOS, 100P is always a supported scale factor.
   // For Windows we have a separate case in this function.
   supported_scale_factors.push_back(SCALE_FACTOR_100P);
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
 #endif
