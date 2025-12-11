--- components/optimization_guide/core/optimization_guide_features.cc.orig	2025-12-10 15:04:57 UTC
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -98,7 +98,7 @@ BASE_FEATURE(kOptimizationGuideModelExecution,
 // Whether to use the on device model service in optimization guide.
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
