--- gpu/vulkan/vulkan_util.cc.orig	2024-02-04 14:46:08 UTC
+++ gpu/vulkan/vulkan_util.cc
@@ -433,7 +433,7 @@ bool CheckVulkanCompabilities(const VulkanInfo& vulkan
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
