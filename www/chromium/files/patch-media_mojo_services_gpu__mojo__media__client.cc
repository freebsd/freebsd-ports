--- media/mojo/services/gpu_mojo_media_client.cc.orig	2020-07-07 21:58:16 UTC
+++ media/mojo/services/gpu_mojo_media_client.cc
@@ -63,7 +63,7 @@ namespace media {
 namespace {
 
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_MACOSX) || \
-    defined(OS_WIN) || defined(OS_LINUX)
+    defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 gpu::CommandBufferStub* GetCommandBufferStub(
     scoped_refptr<base::SingleThreadTaskRunner> gpu_task_runner,
     base::WeakPtr<MediaGpuChannelManager> media_gpu_channel_manager,
@@ -280,7 +280,7 @@ std::unique_ptr<VideoDecoder> GpuMojoMediaClient::Crea
                                 command_buffer_id->route_id));
       }
 
-#elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 #if defined(OS_WIN)
       // Don't instantiate the DXVA decoder if it's not supported.
       if (gpu_workarounds_.disable_dxva_video_decoder)
