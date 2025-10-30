--- gpu/command_buffer/service/shared_image/gpu_memory_buffer_factory.cc.orig	2025-11-01 06:40:37 UTC
+++ gpu/command_buffer/service/shared_image/gpu_memory_buffer_factory.cc
@@ -14,7 +14,7 @@
 #include "gpu/command_buffer/service/shared_image/gpu_memory_buffer_factory_io_surface.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/shared_image/gpu_memory_buffer_factory_native_pixmap.h"
 #endif
 
@@ -36,7 +36,7 @@ GpuMemoryBufferFactory::CreateNativeType(
   // AHardwareBuffers), but the codebase is structured such that it is easier
   // to create a dummy factory than create no factory.
   return std::make_unique<GpuMemoryBufferFactory>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::make_unique<GpuMemoryBufferFactoryNativePixmap>(
       vulkan_context_provider);
 #elif BUILDFLAG(IS_WIN)
