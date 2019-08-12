--- media/mojo/services/gpu_mojo_media_client.cc.orig	2019-07-24 18:58:30 UTC
+++ media/mojo/services/gpu_mojo_media_client.cc
@@ -55,7 +55,7 @@ namespace media {
 namespace {
 
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_MACOSX) || \
-    defined(OS_WIN) || defined(OS_LINUX)
+    defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 gpu::CommandBufferStub* GetCommandBufferStub(
     base::WeakPtr<MediaGpuChannelManager> media_gpu_channel_manager,
     base::UnguessableToken channel_token,
@@ -199,7 +199,7 @@ std::unique_ptr<VideoDecoder> GpuMojoMediaClient::Crea
       std::make_unique<VideoFrameFactoryImpl>(
           gpu_task_runner_, std::move(get_stub_cb), gpu_preferences_));
 #elif defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
       video_decoder = VdaVideoDecoder::Create(
           task_runner, gpu_task_runner_, media_log->Clone(), target_color_space,
           gpu_preferences_, gpu_workarounds_,
