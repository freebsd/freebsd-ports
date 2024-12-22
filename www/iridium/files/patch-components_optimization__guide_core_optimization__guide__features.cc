--- components/optimization_guide/core/optimization_guide_features.cc.orig	2024-12-22 12:24:29 UTC
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -140,7 +140,7 @@ BASE_FEATURE(kOptimizationGuideModelExecution,
 // Whether to use the on device model service in optimization guide.
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
              "OptimizationGuideOnDeviceModel",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
