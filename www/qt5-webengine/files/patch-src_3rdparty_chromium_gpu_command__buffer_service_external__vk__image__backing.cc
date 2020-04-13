--- src/3rdparty/chromium/gpu/command_buffer/service/external_vk_image_backing.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/external_vk_image_backing.cc
@@ -25,7 +25,7 @@
 #include "gpu/vulkan/fuchsia/vulkan_fuchsia_ext.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define GL_HANDLE_TYPE_OPAQUE_FD_EXT 0x9586
 #endif
 
@@ -451,7 +451,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
 #if defined(OS_FUCHSIA)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   GrVkImageInfo image_info;
   bool result = backend_texture_.getVkImageInfo(&image_info);
   DCHECK(result);
@@ -520,7 +520,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
   }
   return std::make_unique<ExternalVkImageGlRepresentation>(
       manager, this, tracker, texture_, texture_->service_id());
-#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA)
+#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 #error Unsupported OS
 #endif
 }
