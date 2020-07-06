--- src/3rdparty/chromium/gpu/command_buffer/service/external_vk_image_backing.h.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/external_vk_image_backing.h
@@ -131,7 +131,7 @@ class ExternalVkImageBacking final : public SharedImag
                          base::Optional<DawnTextureFormat> dawn_format,
                          base::Optional<uint32_t> memory_type_index);
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Extract file descriptor from image
   int GetMemoryFd(const GrVkImageInfo& image_info);
 #endif
