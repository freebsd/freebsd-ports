--- gpu/vulkan/vulkan_util.cc.orig	2026-07-01 06:24:19 UTC
+++ gpu/vulkan/vulkan_util.cc
@@ -278,7 +278,7 @@ bool CheckVulkanCompatibilities(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
