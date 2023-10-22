--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2023-11-22 14:00:11 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -773,7 +773,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1223,7 +1223,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
     }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     is_webgpu_compatible = (gpu_memory_buffer != nullptr);
     if (is_webgpu_compatible) {
       is_webgpu_compatible &=
@@ -1242,7 +1242,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
                        gpu::SHARED_IMAGE_USAGE_DISPLAY_READ |
                        gpu::SHARED_IMAGE_USAGE_SCANOUT;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/1241537): Always add the flag once the
       // OzoneImageBacking is by default turned on.
       if (base::CommandLine::ForCurrentProcess()->HasSwitch(
