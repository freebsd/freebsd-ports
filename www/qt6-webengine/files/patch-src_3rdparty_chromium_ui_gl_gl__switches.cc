--- src/3rdparty/chromium/ui/gl/gl_switches.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/gl/gl_switches.cc
@@ -14,7 +14,7 @@
 #include "base/android/build_info.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) && BUILDFLAG(ENABLE_VULKAN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_VULKAN)
 #include <vulkan/vulkan_core.h>
 #include "third_party/angle/src/gpu_info_util/SystemInfo.h"  // nogncheck
 #endif
@@ -321,7 +321,7 @@ bool IsDefaultANGLEVulkan() {
     return false;
   }
 #endif  // BUILDFLAG(IS_ANDROID)
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) && BUILDFLAG(ENABLE_VULKAN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_VULKAN)
   angle::SystemInfo system_info;
   {
     GPU_STARTUP_TRACE_EVENT("angle::GetSystemInfoVulkan");
@@ -374,7 +374,7 @@ bool IsDefaultANGLEVulkan() {
   }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // AMDVLK driver is buggy, so disable Vulkan with AMDVLK for now.
   // crbug.com/1340081
   if (active_gpu.driverId == VK_DRIVER_ID_AMD_OPEN_SOURCE)
