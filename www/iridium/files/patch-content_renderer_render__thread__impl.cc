--- content/renderer/render_thread_impl.cc.orig	2025-02-22 18:06:53 UTC
+++ content/renderer/render_thread_impl.cc
@@ -211,6 +211,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -1047,7 +1049,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
                              kGpuStreamIdMedia, kGpuStreamPriorityMedia);
 
   const bool enable_video_decode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kAcceleratedVideoDecodeLinux) &&
 #endif  // BUILDFLAG(IS_LINUX)
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
@@ -1056,7 +1058,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
        gpu::kGpuFeatureStatusEnabled);
 
   const bool enable_video_encode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kAcceleratedVideoEncodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoEncode) &&
@@ -1849,7 +1851,7 @@ RenderThreadImpl::CreateMediaMojoCodecFactory(
     bool enable_video_encode_accelerator) {
   mojo::PendingRemote<media::mojom::VideoEncodeAcceleratorProvider>
       vea_provider;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseOutOfProcessVideoEncoding)) {
     BindHostReceiver(vea_provider.InitWithNewPipeAndPassReceiver());
   } else {
