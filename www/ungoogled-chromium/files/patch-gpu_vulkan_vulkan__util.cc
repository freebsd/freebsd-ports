--- gpu/vulkan/vulkan_util.cc.orig	2024-02-25 20:22:18 UTC
+++ gpu/vulkan/vulkan_util.cc
@@ -443,7 +443,7 @@ bool CheckVulkanCompatibilities(const VulkanInfo& vulk
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
