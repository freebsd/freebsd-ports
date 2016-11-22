--- ui/base/resource/resource_bundle.cc.orig	2016-07-20 22:03:45.000000000 +0300
+++ ui/base/resource/resource_bundle.cc	2016-08-01 22:13:38.986790000 +0300
@@ -626,7 +626,7 @@
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -686,7 +686,7 @@
     supported_scale_factors.push_back(SCALE_FACTOR_100P);
   }
 #elif defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
   ui::SetSupportedScaleFactors(supported_scale_factors);
