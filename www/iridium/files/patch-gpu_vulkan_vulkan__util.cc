--- gpu/vulkan/vulkan_util.cc.orig	2026-08-13 16:48:13 UTC
+++ gpu/vulkan/vulkan_util.cc
@@ -278,7 +278,7 @@ bool CheckVulkanCompatibilities(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
