--- gpu/command_buffer/service/external_vk_image_backing.cc.orig	2020-03-03 18:53:55 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.cc
@@ -26,7 +26,7 @@
 #include "ui/gl/buildflags.h"
 #include "ui/gl/gl_context.h"
 
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/external_vk_image_dawn_representation.h"
 #endif
 
@@ -34,7 +34,7 @@
 #include "gpu/vulkan/fuchsia/vulkan_fuchsia_ext.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define GL_HANDLE_TYPE_OPAQUE_FD_EXT 0x9586
 #endif
 
@@ -535,7 +535,7 @@ std::unique_ptr<SharedImageRepresentationDawn>
 ExternalVkImageBacking::ProduceDawn(SharedImageManager* manager,
                                     MemoryTypeTracker* tracker,
                                     WGPUDevice wgpuDevice) {
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   if (!wgpu_format_) {
     DLOG(ERROR) << "Format not supported for Dawn";
     return nullptr;
@@ -558,14 +558,14 @@ ExternalVkImageBacking::ProduceDawn(SharedImageManager
   return std::make_unique<ExternalVkImageDawnRepresentation>(
       manager, this, tracker, wgpuDevice, wgpu_format_.value(), memory_fd,
       image_info.fAlloc.fSize, memory_type_index_.value());
-#else  // !defined(OS_LINUX) || !BUILDFLAG(USE_DAWN)
+#else  // !defined(OS_LINUX) || !defined(OS_BSD) || !BUILDFLAG(USE_DAWN)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
 #endif
 }
 
 GLuint ExternalVkImageBacking::ProduceGLTextureInternal() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   GrVkImageInfo image_info;
   bool result = backend_texture_.getVkImageInfo(&image_info);
   DCHECK(result);
@@ -629,7 +629,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
     return nullptr;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!texture_) {
     GLuint texture_service_id = ProduceGLTextureInternal();
     if (!texture_service_id)
@@ -675,7 +675,7 @@ ExternalVkImageBacking::ProduceGLTexturePassthrough(
     return nullptr;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!texture_passthrough_) {
     GLuint texture_service_id = ProduceGLTextureInternal();
     if (!texture_service_id)
@@ -713,7 +713,7 @@ ExternalVkImageBacking::ProduceSkia(
                                                              tracker);
 }
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
 int ExternalVkImageBacking::GetMemoryFd(const GrVkImageInfo& image_info) {
   VkMemoryGetFdInfoKHR get_fd_info;
   get_fd_info.sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
