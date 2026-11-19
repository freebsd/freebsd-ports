--- gpu/command_buffer/service/shared_image/compound_image_backing.cc.orig	2026-11-19 12:25:27 UTC
+++ gpu/command_buffer/service/shared_image/compound_image_backing.cc
@@ -66,7 +66,7 @@ gfx::GpuMemoryBufferType GetNativeBufferType() {
   return gfx::GpuMemoryBufferType::IO_SURFACE_BUFFER;
 #elif BUILDFLAG(IS_ANDROID)
   return gfx::GpuMemoryBufferType::ANDROID_HARDWARE_BUFFER;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return gfx::GpuMemoryBufferType::NATIVE_PIXMAP;
 #elif BUILDFLAG(IS_WIN)
   return gfx::GpuMemoryBufferType::DXGI_SHARED_HANDLE;
