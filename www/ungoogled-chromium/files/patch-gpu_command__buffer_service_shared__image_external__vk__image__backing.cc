--- gpu/command_buffer/service/shared_image/external_vk_image_backing.cc.orig	2022-12-02 17:56:32 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing.cc
@@ -32,7 +32,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_dawn_representation.h"
 #endif
 
@@ -570,7 +570,7 @@ std::unique_ptr<DawnImageRepresentation> ExternalVkIma
     MemoryTypeTracker* tracker,
     WGPUDevice wgpuDevice,
     WGPUBackendType backend_type) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = viz::ToWGPUFormat(format());
 
   if (wgpu_format == WGPUTextureFormat_Undefined) {
