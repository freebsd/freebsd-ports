--- src/3rdparty/chromium/gpu/config/gpu_finch_features.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_finch_features.cc
@@ -148,7 +148,7 @@ const base::FeatureParam<std::string>
 // DefaultEnableGpuRasterization has launched on Mac, Windows, ChromeOS,
 // Android and Linux.
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDefaultEnableGpuRasterization,
              "DefaultEnableGpuRasterization",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -162,7 +162,7 @@ BASE_FEATURE(kDefaultEnableGpuRasterization,
 // Enables the use of out of process rasterization for canvas.
 #if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_WIN) ||         \
     (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64)) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kCanvasOopRasterization,
              "CanvasOopRasterization",
              base::FEATURE_ENABLED_BY_DEFAULT);
