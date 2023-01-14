--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image_backing_factory_gl_texture.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image_backing_factory_gl_texture.cc
@@ -145,7 +145,7 @@ bool SharedImageBackingFactoryGLTexture::IsSupported(
   // Linux and ChromeOS support WebGPU/Compat on GL. All other platforms
   // do not support WebGPU on GL.
   if (usage & SHARED_IMAGE_USAGE_WEBGPU) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
     if (use_webgpu_adapter_ != WebGPUAdapterName::kCompat) {
       return false;
     }
