--- gpu/vulkan/vulkan_image.h.orig	2021-09-14 01:51:58 UTC
+++ gpu/vulkan/vulkan_image.h
@@ -85,7 +85,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanImage {
       VkImageUsageFlags usage,
       VkImageCreateFlags flags);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static std::unique_ptr<VulkanImage> CreateWithExternalMemoryAndModifiers(
       VulkanDeviceQueue* device_queue,
       const gfx::Size& size,
@@ -168,7 +168,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanImage {
       VkImageTiling image_tiling,
       uint32_t queue_family_index);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool InitializeWithExternalMemoryAndModifiers(VulkanDeviceQueue* device_queue,
                                                 const gfx::Size& size,
                                                 VkFormat format,
