--- src/3rdparty/chromium/gpu/config/gpu_finch_features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_finch_features.cc
@@ -154,7 +154,8 @@ BASE_FEATURE(kAllowHardwareBufferUsageFlagsFromVulkanF
 // DefaultEnableGpuRasterization has launched on Mac, Windows, ChromeOS,
 // Android and Linux.
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDefaultEnableGpuRasterization,
              "DefaultEnableGpuRasterization",
              base::FEATURE_ENABLED_BY_DEFAULT);
