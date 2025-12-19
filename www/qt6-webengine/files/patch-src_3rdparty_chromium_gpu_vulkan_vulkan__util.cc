--- src/3rdparty/chromium/gpu/vulkan/vulkan_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_util.cc
@@ -468,7 +468,7 @@ bool CheckVulkanCompatibilities(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
