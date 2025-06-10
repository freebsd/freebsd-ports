--- src/3rdparty/chromium/ui/gl/gl_switches.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/ui/gl/gl_switches.cc
@@ -12,7 +12,7 @@
 #include "base/android/build_info.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(ENABLE_VULKAN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_VULKAN)
 #include <vulkan/vulkan_core.h>
 #include "third_party/angle/src/gpu_info_util/SystemInfo.h"  // nogncheck
 #endif
@@ -291,7 +291,7 @@ bool IsDefaultANGLEVulkan() {
       base::android::SDK_VERSION_Q)
     return false;
 #endif  // BUILDFLAG(IS_ANDROID)
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(ENABLE_VULKAN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_VULKAN)
   angle::SystemInfo system_info;
   if (!angle::GetSystemInfoVulkan(&system_info))
     return false;
@@ -303,7 +303,7 @@ bool IsDefaultANGLEVulkan() {
 
   const auto& active_gpu = system_info.gpus[system_info.activeGPUIndex];
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Vulkan 1.1 is required.
   if (active_gpu.driverApiVersion < VK_VERSION_1_1)
     return false;
