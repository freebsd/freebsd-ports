--- src/3rdparty/chromium/ui/gl/gl_switches.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/ui/gl/gl_switches.cc
@@ -12,7 +12,7 @@
 #include "base/android/build_info.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_VULKAN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_VULKAN)
 #include <vulkan/vulkan_core.h>
 #include "third_party/angle/src/gpu_info_util/SystemInfo.h"  // nogncheck
 #endif
@@ -298,7 +298,7 @@ bool IsDefaultANGLEVulkan() {
       base::android::SDK_VERSION_Q)
     return false;
 #endif  // BUILDFLAG(IS_ANDROID)
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_VULKAN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_VULKAN)
   angle::SystemInfo system_info;
   if (!angle::GetSystemInfoVulkan(&system_info))
     return false;
