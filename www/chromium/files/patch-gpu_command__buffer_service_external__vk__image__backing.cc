--- gpu/command_buffer/service/external_vk_image_backing.cc.orig	2020-07-07 21:58:16 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.cc
@@ -29,7 +29,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/external_vk_image_dawn_representation.h"
 #endif
 
@@ -503,7 +503,7 @@ std::unique_ptr<SharedImageRepresentationDawn>
 ExternalVkImageBacking::ProduceDawn(SharedImageManager* manager,
                                     MemoryTypeTracker* tracker,
                                     WGPUDevice wgpuDevice) {
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = viz::ToWGPUFormat(format());
 
   if (wgpu_format == WGPUTextureFormat_Undefined) {
@@ -522,7 +522,7 @@ ExternalVkImageBacking::ProduceDawn(SharedImageManager
 
   return std::make_unique<ExternalVkImageDawnRepresentation>(
       manager, this, tracker, wgpuDevice, wgpu_format, std::move(memory_fd));
-#else  // !defined(OS_LINUX) || !BUILDFLAG(USE_DAWN)
+#else  // (!defined(OS_LINUX) && !defined(OS_BSD)) || !BUILDFLAG(USE_DAWN)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
 #endif
@@ -535,7 +535,7 @@ GLuint ExternalVkImageBacking::ProduceGLTextureInterna
   gl::GLApi* api = gl::g_current_gl_context;
   base::Optional<ScopedDedicatedMemoryObject> memory_object;
   if (!use_separate_gl_texture()) {
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     auto memory_fd = image_->GetMemoryFd();
     if (!memory_fd.is_valid())
       return 0;
