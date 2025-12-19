--- src/3rdparty/chromium/components/optimization_guide/core/optimization_guide_features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/optimization_guide/core/optimization_guide_features.cc
@@ -137,7 +137,7 @@ BASE_FEATURE(kOptimizationGuideOnDeviceModel,
 // Whether to use the on device model service in optimization guide.
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
              "OptimizationGuideOnDeviceModel",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
