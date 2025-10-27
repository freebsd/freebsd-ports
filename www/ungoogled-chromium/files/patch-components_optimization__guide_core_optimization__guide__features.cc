--- components/optimization_guide/core/optimization_guide_features.cc.orig	2025-10-21 16:57:35 UTC
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -120,7 +120,7 @@ BASE_FEATURE(kOptimizationGuideModelExecution,
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
              "OptimizationGuideOnDeviceModel",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
