--- ui/base/resource/resource_bundle.cc.orig	2017-03-09 20:04:49 UTC
+++ ui/base/resource/resource_bundle.cc
@@ -650,7 +650,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -709,7 +709,7 @@ void ResourceBundle::InitSharedInstance(
     supported_scale_factors.push_back(SCALE_FACTOR_100P);
   }
 #elif defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
   ui::SetSupportedScaleFactors(supported_scale_factors);
