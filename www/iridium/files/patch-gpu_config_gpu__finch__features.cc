--- gpu/config/gpu_finch_features.cc.orig	2025-12-10 15:04:57 UTC
+++ gpu/config/gpu_finch_features.cc
@@ -122,7 +122,8 @@ BASE_FEATURE(kAllowHardwareBufferUsageFlagsFromVulkanF
 // Android and Linux.
 BASE_FEATURE(kDefaultEnableGpuRasterization,
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
