--- components/viz/service/display_embedder/skia_output_device_buffer_queue.cc.orig	2024-08-27 06:28:16 UTC
+++ components/viz/service/display_embedder/skia_output_device_buffer_queue.cc
@@ -175,7 +175,7 @@ SkiaOutputDeviceBufferQueue::SkiaOutputDeviceBufferQue
   capabilities_.only_invalidates_damage_rect = false;
   capabilities_.number_of_buffers = 3;
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   capabilities_.renderer_allocates_images =
       ::features::ShouldRendererAllocateImages();
 #else
