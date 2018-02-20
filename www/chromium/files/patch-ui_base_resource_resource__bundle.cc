--- ui/base/resource/resource_bundle.cc.orig	2017-12-15 02:04:51.000000000 +0100
+++ ui/base/resource/resource_bundle.cc	2017-12-24 20:04:48.415881000 +0100
@@ -707,7 +707,7 @@
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -762,7 +762,7 @@
   } else {
     supported_scale_factors.push_back(SCALE_FACTOR_100P);
   }
-#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
   ui::SetSupportedScaleFactors(supported_scale_factors);
