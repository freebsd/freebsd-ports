--- gpu/command_buffer/service/external_vk_image_backing.cc.orig	2019-10-21 19:06:34 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.cc
@@ -23,7 +23,7 @@
 #include "ui/gl/buildflags.h"
 #include "ui/gl/gl_context.h"
 
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/external_vk_image_dawn_representation.h"
 #endif
 
@@ -31,7 +31,7 @@
 #include "gpu/vulkan/fuchsia/vulkan_fuchsia_ext.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define GL_HANDLE_TYPE_OPAQUE_FD_EXT 0x9586
 #endif
 
@@ -504,7 +504,7 @@ std::unique_ptr<SharedImageRepresentationDawn>
 ExternalVkImageBacking::ProduceDawn(SharedImageManager* manager,
                                     MemoryTypeTracker* tracker,
                                     DawnDevice dawnDevice) {
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   if (!dawn_format_) {
     DLOG(ERROR) << "Format not supported for Dawn";
     return nullptr;
@@ -527,7 +527,7 @@ ExternalVkImageBacking::ProduceDawn(SharedImageManager
   return std::make_unique<ExternalVkImageDawnRepresentation>(
       manager, this, tracker, dawnDevice, dawn_format_.value(), memory_fd,
       image_info.fAlloc.fSize, memory_type_index_.value());
-#else  // !defined(OS_LINUX) || !BUILDFLAG(USE_DAWN)
+#else  // !defined(OS_LINUX) || !defined(OS_BSD) || !BUILDFLAG(USE_DAWN)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
 #endif
@@ -544,7 +544,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
 #if defined(OS_FUCHSIA)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   GrVkImageInfo image_info;
   bool result = backend_texture_.getVkImageInfo(&image_info);
   DCHECK(result);
@@ -604,7 +604,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
   }
   return std::make_unique<ExternalVkImageGlRepresentation>(
       manager, this, tracker, texture_, texture_->service_id());
-#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA)
+#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 #error Unsupported OS
 #endif
 }
@@ -630,7 +630,7 @@ ExternalVkImageBacking::ProduceSkia(
                                                              tracker);
 }
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
 int ExternalVkImageBacking::GetMemoryFd(const GrVkImageInfo& image_info) {
   VkMemoryGetFdInfoKHR get_fd_info;
   get_fd_info.sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
