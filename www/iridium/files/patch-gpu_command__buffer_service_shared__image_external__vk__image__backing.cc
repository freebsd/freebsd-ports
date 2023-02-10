--- gpu/command_buffer/service/shared_image/external_vk_image_backing.cc.orig	2023-01-17 19:19:00 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing.cc
@@ -32,7 +32,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_dawn_representation.h"
 #endif
 
@@ -572,7 +572,7 @@ std::unique_ptr<DawnImageRepresentation> ExternalVkIma
     MemoryTypeTracker* tracker,
     WGPUDevice wgpuDevice,
     WGPUBackendType backend_type) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = viz::ToWGPUFormat(format());
 
   if (wgpu_format == WGPUTextureFormat_Undefined) {
