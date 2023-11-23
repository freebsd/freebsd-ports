--- src/3rdparty/chromium/gpu/vulkan/vulkan_util.cc.orig	2022-07-22 17:30:31 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_util.cc
@@ -199,7 +199,7 @@ bool CheckVulkanCompabilities(const VulkanInfo& vulkan
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
