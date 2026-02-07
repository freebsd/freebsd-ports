--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/shared_image_factory.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/shared_image_factory.cc
@@ -49,7 +49,7 @@
 #include "gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.h"
 #include "gpu/vulkan/vulkan_device_queue.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.h"
 #endif
 
@@ -113,7 +113,7 @@ gfx::GpuMemoryBufferType GetNativeBufferType() {
   return gfx::GpuMemoryBufferType::IO_SURFACE_BUFFER;
 #elif BUILDFLAG(IS_ANDROID)
   return gfx::GpuMemoryBufferType::ANDROID_HARDWARE_BUFFER;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return gfx::GpuMemoryBufferType::NATIVE_PIXMAP;
 #elif BUILDFLAG(IS_WIN)
   return gfx::GpuMemoryBufferType::DXGI_SHARED_HANDLE;
@@ -335,7 +335,7 @@ SharedImageFactory::SharedImageFactory(
         context_state_, workarounds_);
     factories_.push_back(std::move(ozone_factory));
   }
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
   if (gr_context_type_ == GrContextType::kVulkan) {
     auto external_vk_image_factory =
         std::make_unique<ExternalVkImageBackingFactory>(context_state_);
