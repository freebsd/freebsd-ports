--- gpu/vulkan/vulkan_util.cc.orig	2025-12-06 13:30:52 UTC
+++ gpu/vulkan/vulkan_util.cc
@@ -474,7 +474,7 @@ bool CheckVulkanCompatibilities(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
