--- gpu/command_buffer/service/shared_image/shared_image_factory.cc.orig	2026-11-19 12:25:27 UTC
+++ gpu/command_buffer/service/shared_image/shared_image_factory.cc
@@ -56,7 +56,7 @@
 #include "gpu/command_buffer/service/vulkan_context_provider.h"
 #include "gpu/vulkan/vulkan_device_queue.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.h"
 #endif
 
@@ -206,7 +206,7 @@ const char* SharedImageFactory::GmbTypeToString(gfx::G
     case gfx::IO_SURFACE_BUFFER:
       return "platform";
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case gfx::NATIVE_PIXMAP:
       return "platform";
 #endif
@@ -379,7 +379,7 @@ SharedImageFactory::SharedImageFactory(
     factories_.push_back(std::move(ozone_factory));
   }
 
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
   if (gr_context_type_ == GrContextType::kVulkan
 #if BUILDFLAG(USE_WEBGPU_ON_VULKAN_VIA_GL_INTEROP)
       /* We support GL context for WebGPU gl-vulkan interop (on linux).*/
@@ -912,7 +912,7 @@ void SharedImageFactory::LogGetFactoryFailed(gpu::Shar
   }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // VizBufferQueue with Vulkan enabled over command-line for Linux does not
   // work. Suppress dumps for these cases.
   if (context_state_->GrContextIsVulkan() &&
