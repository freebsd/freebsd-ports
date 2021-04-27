--- media/mojo/services/gpu_mojo_media_client.cc.orig	2021-04-14 18:41:05 UTC
+++ media/mojo/services/gpu_mojo_media_client.cc
@@ -67,7 +67,7 @@ namespace media {
 namespace {
 
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN) || defined(OS_LINUX)
+    defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 gpu::CommandBufferStub* GetCommandBufferStub(
     scoped_refptr<base::SingleThreadTaskRunner> gpu_task_runner,
     base::WeakPtr<MediaGpuChannelManager> media_gpu_channel_manager,
@@ -289,7 +289,7 @@ std::unique_ptr<VideoDecoder> GpuMojoMediaClient::Crea
                                 command_buffer_id->route_id));
       }
 
-#elif defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#elif defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #if defined(OS_WIN)
       // Don't instantiate the DXVA decoder if it's not supported.
