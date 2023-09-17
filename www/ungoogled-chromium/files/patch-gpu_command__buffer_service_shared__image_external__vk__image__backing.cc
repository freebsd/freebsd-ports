--- gpu/command_buffer/service/shared_image/external_vk_image_backing.cc.orig	2023-09-17 07:59:53 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing.cc
@@ -46,7 +46,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_dawn_representation.h"
 #endif
 
@@ -656,7 +656,7 @@ std::unique_ptr<DawnImageRepresentation> ExternalVkIma
     const wgpu::Device& wgpuDevice,
     wgpu::BackendType backend_type,
     std::vector<wgpu::TextureFormat> view_formats) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = ToDawnFormat(format());
 
   if (wgpu_format == wgpu::TextureFormat::Undefined) {
