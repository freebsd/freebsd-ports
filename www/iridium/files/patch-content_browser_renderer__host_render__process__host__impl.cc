--- content/browser/renderer_host/render_process_host_impl.cc.orig	2023-11-22 14:00:11 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -220,7 +220,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -951,7 +951,7 @@ static constexpr size_t kUnknownPlatformProcessLimit =
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1094,7 +1094,7 @@ class RenderProcessHostImpl::IOThreadHostImpl : public
         return;
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
       ConnectToFontService(std::move(font_receiver));
       return;
@@ -1183,7 +1183,7 @@ class RenderProcessHostImpl::IOThreadHostImpl : public
   std::unique_ptr<service_manager::BinderRegistry> binders_;
   mojo::Receiver<mojom::ChildProcessHost> receiver_{this};
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::Remote<media::mojom::VideoEncodeAcceleratorProviderFactory>
       video_encode_accelerator_factory_remote_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -3256,7 +3256,7 @@ void RenderProcessHostImpl::AppendRendererCommandLine(
             base::TimeTicks::UnixEpoch().since_origin().InMicroseconds()));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Append `kDisableVideoCaptureUseGpuMemoryBuffer` flag if there is no support
   // for NV12 GPU memory buffer.
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled() &&
@@ -3316,6 +3316,8 @@ void RenderProcessHostImpl::PropagateBrowserCommandLin
     switches::kDisableSpeechAPI,
     switches::kDisableThreadedCompositing,
     switches::kDisableTouchDragDrop,
+    switches::kDisableUnveil,
+    switches::kTrk,
     switches::kDisableUseSharedImagesForPepperVideo,
     switches::kDisableV8IdleTasks,
     switches::kDisableVideoCaptureUseGpuMemoryBuffer,
