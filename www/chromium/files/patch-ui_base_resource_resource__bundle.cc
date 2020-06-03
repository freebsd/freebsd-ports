--- ui/base/resource/resource_bundle.cc.orig	2020-05-13 18:40:03 UTC
+++ ui/base/resource/resource_bundle.cc
@@ -830,7 +830,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -883,7 +883,7 @@ void ResourceBundle::InitSharedInstance(Delegate* dele
   // On platforms other than iOS, 100P is always a supported scale factor.
   // For Windows we have a separate case in this function.
   supported_scale_factors.push_back(SCALE_FACTOR_100P);
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
 #endif
