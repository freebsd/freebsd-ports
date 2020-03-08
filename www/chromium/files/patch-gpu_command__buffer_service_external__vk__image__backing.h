--- gpu/command_buffer/service/external_vk_image_backing.h.orig	2020-03-03 18:53:55 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.h
@@ -135,7 +135,7 @@ class ExternalVkImageBacking final : public SharedImag
                          base::Optional<WGPUTextureFormat> wgpu_format,
                          base::Optional<uint32_t> memory_type_index);
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Extract file descriptor from image
   int GetMemoryFd(const GrVkImageInfo& image_info);
 #endif
