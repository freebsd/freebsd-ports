--- content/browser/renderer_host/render_process_host_impl.cc.orig	2024-07-30 11:12:21 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -224,7 +224,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -965,7 +965,7 @@ static constexpr size_t kUnknownPlatformProcessLimit =
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1151,7 +1151,7 @@ class RenderProcessHostImpl::IOThreadHostImpl : public
   IOThreadHostImpl& operator=(const IOThreadHostImpl& other) = delete;
 
   void SetPid(base::ProcessId child_pid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     child_thread_type_switcher_.SetPid(child_pid);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   }
@@ -1172,7 +1172,7 @@ class RenderProcessHostImpl::IOThreadHostImpl : public
         return;
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
       ConnectToFontService(std::move(font_receiver));
       return;
@@ -1266,7 +1266,7 @@ class RenderProcessHostImpl::IOThreadHostImpl : public
   std::unique_ptr<service_manager::BinderRegistry> binders_;
   mojo::Receiver<mojom::ChildProcessHost> receiver_{this};
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::Remote<media::mojom::VideoEncodeAcceleratorProviderFactory>
       video_encode_accelerator_factory_remote_;
   ChildThreadTypeSwitcher child_thread_type_switcher_;
@@ -3429,7 +3429,7 @@ void RenderProcessHostImpl::AppendRendererCommandLine(
             base::TimeTicks::UnixEpoch().since_origin().InMicroseconds()));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Append `kDisableVideoCaptureUseGpuMemoryBuffer` flag if there is no support
   // for NV12 GPU memory buffer.
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled() &&
@@ -3487,6 +3487,7 @@ void RenderProcessHostImpl::PropagateBrowserCommandLin
     switches::kDisableSpeechAPI,
     switches::kDisableThreadedCompositing,
     switches::kDisableTouchDragDrop,
+    switches::kDisableUnveil,
     switches::kDisableV8IdleTasks,
     switches::kDisableVideoCaptureUseGpuMemoryBuffer,
     switches::kDisableWebGLImageChromium,
