--- gpu/vulkan/vulkan_image.cc.orig	2021-09-14 01:51:58 UTC
+++ gpu/vulkan/vulkan_image.cc
@@ -326,7 +326,7 @@ bool VulkanImage::InitializeWithExternalMemory(
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   VkPhysicalDeviceImageDrmFormatModifierInfoEXT modifier_info = {
       .sType =
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT,
