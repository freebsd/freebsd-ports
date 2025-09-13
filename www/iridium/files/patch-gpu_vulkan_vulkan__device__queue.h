--- gpu/vulkan/vulkan_device_queue.h.orig	2025-09-11 13:19:19 UTC
+++ gpu/vulkan/vulkan_device_queue.h
@@ -188,7 +188,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanDeviceQueue
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   VkPhysicalDeviceSamplerYcbcrConversionFeatures
       sampler_ycbcr_conversion_features_{
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES};
