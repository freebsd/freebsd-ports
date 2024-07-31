--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2024-07-30 11:12:21 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -107,7 +107,7 @@ class GpuMemoryBufferVideoFramePool::PoolImpl
                 gpu::SHARED_IMAGE_USAGE_RASTER_READ |
                 gpu::SHARED_IMAGE_USAGE_DISPLAY_READ |
                 gpu::SHARED_IMAGE_USAGE_SCANOUT;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40194712): Always add the flag once the
     // OzoneImageBacking is by default turned on.
     if (base::CommandLine::ForCurrentProcess()->HasSwitch(
@@ -802,7 +802,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1347,7 +1347,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
         media::IOSurfaceIsWebGPUCompatible(handle.io_surface.get());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     is_webgpu_compatible =
         handle.native_pixmap_handle.supports_zero_copy_webgpu_import;
 #endif
