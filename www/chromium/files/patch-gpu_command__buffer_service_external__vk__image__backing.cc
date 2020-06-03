--- gpu/command_buffer/service/external_vk_image_backing.cc.orig	2020-05-13 18:40:32 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.cc
@@ -29,7 +29,7 @@
 #include "ui/gl/buildflags.h"
 #include "ui/gl/gl_context.h"
 
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/external_vk_image_dawn_representation.h"
 #endif
 
@@ -37,7 +37,7 @@
 #include "gpu/vulkan/fuchsia/vulkan_fuchsia_ext.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #define GL_DEDICATED_MEMORY_OBJECT_EXT 0x9581
 #define GL_TEXTURE_TILING_EXT 0x9580
 #define GL_TILING_TYPES_EXT 0x9583
@@ -510,7 +510,7 @@ std::unique_ptr<SharedImageRepresentationDawn>
 ExternalVkImageBacking::ProduceDawn(SharedImageManager* manager,
                                     MemoryTypeTracker* tracker,
                                     WGPUDevice wgpuDevice) {
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = viz::ToWGPUFormat(format());
 
   if (wgpu_format == WGPUTextureFormat_Undefined) {
@@ -529,14 +529,14 @@ ExternalVkImageBacking::ProduceDawn(SharedImageManager
 
   return std::make_unique<ExternalVkImageDawnRepresentation>(
       manager, this, tracker, wgpuDevice, wgpu_format, std::move(memory_fd));
-#else  // !defined(OS_LINUX) || !BUILDFLAG(USE_DAWN)
+#else  // (!defined(OS_LINUX) && !defined(OS_BSD)) || !BUILDFLAG(USE_DAWN)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
 #endif
 }
 
 GLuint ExternalVkImageBacking::ProduceGLTextureInternal() {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     defined(OS_WIN)
   GrVkImageInfo image_info;
   bool result = backend_texture_.getVkImageInfo(&image_info);
@@ -545,7 +545,7 @@ GLuint ExternalVkImageBacking::ProduceGLTextureInterna
   gl::GLApi* api = gl::g_current_gl_context;
   GLuint memory_object = 0;
   if (!use_separate_gl_texture()) {
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     auto memory_fd = image_->GetMemoryFd();
     if (!memory_fd.is_valid()) {
       return 0;
@@ -608,7 +608,7 @@ GLuint ExternalVkImageBacking::ProduceGLTextureInterna
   }
   api->glBindTextureFn(GL_TEXTURE_2D, old_texture_binding);
   return texture_service_id;
-#else  // !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
+#else  // !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 #error Unsupported OS
 #endif
 }
@@ -622,7 +622,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
     return nullptr;
   }
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     defined(OS_WIN)
   if (!texture_) {
     GLuint texture_service_id = ProduceGLTextureInternal();
@@ -666,7 +666,7 @@ ExternalVkImageBacking::ProduceGLTexturePassthrough(
     return nullptr;
   }
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     defined(OS_WIN)
   if (!texture_passthrough_) {
     GLuint texture_service_id = ProduceGLTextureInternal();
