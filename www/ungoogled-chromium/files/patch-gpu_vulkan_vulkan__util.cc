--- gpu/vulkan/vulkan_util.cc.orig	2025-10-21 16:57:35 UTC
+++ gpu/vulkan/vulkan_util.cc
@@ -481,7 +481,7 @@ bool CheckVulkanCompatibilities(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
