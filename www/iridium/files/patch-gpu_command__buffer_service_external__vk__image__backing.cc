--- gpu/command_buffer/service/external_vk_image_backing.cc.orig	2020-03-16 18:40:32 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.cc
@@ -27,7 +27,7 @@
 #include "ui/gl/buildflags.h"
 #include "ui/gl/gl_context.h"
 
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/external_vk_image_dawn_representation.h"
 #endif
 
@@ -35,7 +35,7 @@
 #include "gpu/vulkan/fuchsia/vulkan_fuchsia_ext.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define GL_HANDLE_TYPE_OPAQUE_FD_EXT 0x9586
 #endif
 
@@ -630,7 +630,7 @@ std::unique_ptr<SharedImageRepresentationDawn>
 ExternalVkImageBacking::ProduceDawn(SharedImageManager* manager,
                                     MemoryTypeTracker* tracker,
                                     WGPUDevice wgpuDevice) {
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   if (!wgpu_format_) {
     DLOG(ERROR) << "Format not supported for Dawn";
     return nullptr;
@@ -653,14 +653,14 @@ ExternalVkImageBacking::ProduceDawn(SharedImageManager
   return std::make_unique<ExternalVkImageDawnRepresentation>(
       manager, this, tracker, wgpuDevice, wgpu_format_.value(), memory_fd,
       image_info.fAlloc.fSize, memory_type_index_.value());
-#else  // !defined(OS_LINUX) || !BUILDFLAG(USE_DAWN)
+#else  // (!defined(OS_LINUX) && !defined(OS_BSD)) || !BUILDFLAG(USE_DAWN)
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
@@ -710,7 +710,7 @@ GLuint ExternalVkImageBacking::ProduceGLTextureInterna
 #elif defined(OS_FUCHSIA)
   NOTIMPLEMENTED_LOG_ONCE();
   return 0;
-#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA)
+#else  // !defined(OS_LINUX) && !defined(OS_BSD) && !defined(OS_FUCHSIA)
 #error Unsupported OS
 #endif
 }
@@ -724,7 +724,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
     return nullptr;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!texture_) {
     GLuint texture_service_id = ProduceGLTextureInternal();
     if (!texture_service_id)
@@ -755,7 +755,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
 #elif defined(OS_FUCHSIA)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
-#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA)
+#else  // !defined(OS_LINUX) && !defined(OS_BSD) && !defined(OS_FUCHSIA)
 #error Unsupported OS
 #endif
 }
@@ -770,7 +770,7 @@ ExternalVkImageBacking::ProduceGLTexturePassthrough(
     return nullptr;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!texture_passthrough_) {
     GLuint texture_service_id = ProduceGLTextureInternal();
     if (!texture_service_id)
@@ -790,7 +790,7 @@ ExternalVkImageBacking::ProduceGLTexturePassthrough(
 #elif defined(OS_FUCHSIA)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
-#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA)
+#else  // !defined(OS_LINUX) && !defined(OS_BSD) && !defined(OS_FUCHSIA)
 #error Unsupported OS
 #endif
 }
@@ -808,7 +808,7 @@ ExternalVkImageBacking::ProduceSkia(
                                                              tracker);
 }
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
 int ExternalVkImageBacking::GetMemoryFd(const GrVkImageInfo& image_info) {
   VkMemoryGetFdInfoKHR get_fd_info;
   get_fd_info.sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
