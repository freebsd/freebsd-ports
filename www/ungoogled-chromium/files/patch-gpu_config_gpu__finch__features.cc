--- gpu/config/gpu_finch_features.cc.orig	2025-10-21 16:57:35 UTC
+++ gpu/config/gpu_finch_features.cc
@@ -125,7 +125,8 @@ BASE_FEATURE(AllowHardwareBufferUsageFlagsFromVulkanFo
 // Android and Linux.
 BASE_FEATURE(DefaultEnableGpuRasterization,
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
