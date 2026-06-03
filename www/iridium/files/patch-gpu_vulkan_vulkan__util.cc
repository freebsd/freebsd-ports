--- gpu/vulkan/vulkan_util.cc.orig	2026-03-24 16:59:08 UTC
+++ gpu/vulkan/vulkan_util.cc
@@ -469,7 +469,7 @@ bool CheckVulkanCompatibilities(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
