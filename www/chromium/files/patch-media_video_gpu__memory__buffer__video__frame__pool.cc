--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2024-05-21 18:07:39 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -802,7 +802,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1284,7 +1284,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
     }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     is_webgpu_compatible = (gpu_memory_buffer != nullptr);
     if (is_webgpu_compatible) {
       is_webgpu_compatible &=
@@ -1303,7 +1303,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
                        gpu::SHARED_IMAGE_USAGE_DISPLAY_READ |
                        gpu::SHARED_IMAGE_USAGE_SCANOUT;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/1241537): Always add the flag once the
       // OzoneImageBacking is by default turned on.
       if (base::CommandLine::ForCurrentProcess()->HasSwitch(
