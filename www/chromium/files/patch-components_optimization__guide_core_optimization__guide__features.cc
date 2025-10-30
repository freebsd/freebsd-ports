--- components/optimization_guide/core/optimization_guide_features.cc.orig	2025-10-30 15:44:36 UTC
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -104,7 +104,7 @@ BASE_FEATURE(kOptimizationGuideModelExecution,
 // Whether to use the on device model service in optimization guide.
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
