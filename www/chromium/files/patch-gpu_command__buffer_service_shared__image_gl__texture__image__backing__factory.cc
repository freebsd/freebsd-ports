--- gpu/command_buffer/service/shared_image/gl_texture_image_backing_factory.cc.orig	2023-02-08 09:03:45 UTC
+++ gpu/command_buffer/service/shared_image/gl_texture_image_backing_factory.cc
@@ -143,7 +143,7 @@ bool GLTextureImageBackingFactory::IsSupported(
   // Linux and ChromeOS support WebGPU/Compat on GL. All other platforms
   // do not support WebGPU on GL.
   if (usage & SHARED_IMAGE_USAGE_WEBGPU) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
     if (use_webgpu_adapter_ != WebGPUAdapterName::kCompat) {
       return false;
     }
