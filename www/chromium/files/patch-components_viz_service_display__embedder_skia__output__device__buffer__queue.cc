--- components/viz/service/display_embedder/skia_output_device_buffer_queue.cc.orig	2024-07-30 11:12:21 UTC
+++ components/viz/service/display_embedder/skia_output_device_buffer_queue.cc
@@ -174,7 +174,7 @@ SkiaOutputDeviceBufferQueue::SkiaOutputDeviceBufferQue
   capabilities_.only_invalidates_damage_rect = false;
   capabilities_.number_of_buffers = 3;
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   capabilities_.renderer_allocates_images =
       ::features::ShouldRendererAllocateImages();
 #else
