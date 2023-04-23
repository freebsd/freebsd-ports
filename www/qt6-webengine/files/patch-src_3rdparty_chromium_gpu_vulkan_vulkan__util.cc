--- src/3rdparty/chromium/gpu/vulkan/vulkan_util.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_util.cc
@@ -195,7 +195,7 @@ bool CheckVulkanCompabilities(const VulkanInfo& vulkan
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
