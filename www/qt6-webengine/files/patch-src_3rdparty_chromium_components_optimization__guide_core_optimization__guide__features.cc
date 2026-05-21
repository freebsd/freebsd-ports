--- src/3rdparty/chromium/components/optimization_guide/core/optimization_guide_features.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/components/optimization_guide/core/optimization_guide_features.cc
@@ -117,7 +117,7 @@ BASE_FEATURE(kOptimizationGuideModelExecution,
 
 // Whether to use the on device model service in optimization guide.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
              "OptimizationGuideOnDeviceModel",
              base::FEATURE_ENABLED_BY_DEFAULT);
