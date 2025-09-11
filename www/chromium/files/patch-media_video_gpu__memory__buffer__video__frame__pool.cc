--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2025-09-06 10:01:20 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -651,7 +651,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1052,7 +1052,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
       media::IOSurfaceIsWebGPUCompatible(handle.io_surface().get());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_webgpu_compatible =
       handle.type == gfx::NATIVE_PIXMAP &&
       handle.native_pixmap_handle().supports_zero_copy_webgpu_import;
@@ -1220,7 +1220,7 @@ GpuMemoryBufferVideoFramePool::PoolImpl::GetOrCreateFr
       si_usage |= gpu::SHARED_IMAGE_USAGE_SCANOUT;
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40194712): Always add the flag once the
     // OzoneImageBacking is by default turned on.
     if (base::CommandLine::ForCurrentProcess()->HasSwitch(
