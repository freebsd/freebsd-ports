--- ui/gl/gl_switches.cc.orig	2025-07-02 06:08:04 UTC
+++ ui/gl/gl_switches.cc
@@ -15,7 +15,7 @@
 #endif
 
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 #include <vulkan/vulkan_core.h>
 #include "third_party/angle/src/gpu_info_util/SystemInfo.h"  // nogncheck
 #endif  // BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) ||
@@ -323,7 +323,7 @@ bool IsDefaultANGLEVulkan() {
   }
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
   angle::SystemInfo system_info;
   {
     GPU_STARTUP_TRACE_EVENT("angle::GetSystemInfoVulkan");
@@ -392,7 +392,7 @@ bool IsDefaultANGLEVulkan() {
   }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // AMDVLK driver is buggy, so disable Vulkan with AMDVLK for now.
   // crbug.com/1340081
   if (active_gpu.driverId == VK_DRIVER_ID_AMD_OPEN_SOURCE)
