--- gpu/command_buffer/service/external_vk_image_backing.cc.orig	2022-06-17 14:20:10 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.cc
@@ -30,7 +30,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/external_vk_image_dawn_representation.h"
 #endif
 
@@ -571,7 +571,7 @@ ExternalVkImageBacking::ProduceDawn(SharedImageManager
                                     MemoryTypeTracker* tracker,
                                     WGPUDevice wgpuDevice,
                                     WGPUBackendType backend_type) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = viz::ToWGPUFormat(format());
 
   if (wgpu_format == WGPUTextureFormat_Undefined) {
