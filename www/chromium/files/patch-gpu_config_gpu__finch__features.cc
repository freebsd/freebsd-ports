--- gpu/config/gpu_finch_features.cc.orig	2024-04-19 13:02:56 UTC
+++ gpu/config/gpu_finch_features.cc
@@ -145,7 +145,7 @@ const base::FeatureParam<std::string>
 BASE_FEATURE(kDefaultEnableGpuRasterization,
              "DefaultEnableGpuRasterization",
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -158,7 +158,7 @@ BASE_FEATURE(kCanvasOopRasterization,
              "CanvasOopRasterization",
 #if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_WIN) ||         \
     (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64)) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
