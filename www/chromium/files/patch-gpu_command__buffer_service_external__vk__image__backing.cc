--- gpu/command_buffer/service/external_vk_image_backing.cc.orig	2021-09-14 01:51:57 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.cc
@@ -31,7 +31,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/external_vk_image_dawn_representation.h"
 #endif
 
@@ -557,7 +557,7 @@ ExternalVkImageBacking::ProduceDawn(SharedImageManager
                                     MemoryTypeTracker* tracker,
                                     WGPUDevice wgpuDevice,
                                     WGPUBackendType backend_type) {
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = viz::ToWGPUFormat(format());
 
   if (wgpu_format == WGPUTextureFormat_Undefined) {
@@ -576,7 +576,7 @@ ExternalVkImageBacking::ProduceDawn(SharedImageManager
 
   return std::make_unique<ExternalVkImageDawnRepresentation>(
       manager, this, tracker, wgpuDevice, wgpu_format, std::move(memory_fd));
-#else  // (!defined(OS_LINUX) && !defined(OS_CHROMEOS)) || !BUILDFLAG(USE_DAWN)
+#else  // (!defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)) || !BUILDFLAG(USE_DAWN)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
 #endif
@@ -589,7 +589,7 @@ GLuint ExternalVkImageBacking::ProduceGLTextureInterna
   gl::GLApi* api = gl::g_current_gl_context;
   absl::optional<ScopedDedicatedMemoryObject> memory_object;
   if (!use_separate_gl_texture()) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
     auto memory_fd = image_->GetMemoryFd();
     if (!memory_fd.is_valid())
       return 0;
