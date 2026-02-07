--- src/3rdparty/chromium/gpu/vulkan/vulkan_device_queue.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_device_queue.h
@@ -182,7 +182,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanDeviceQueue
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   VkPhysicalDeviceSamplerYcbcrConversionFeatures
       sampler_ycbcr_conversion_features_{
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES};
