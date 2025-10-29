--- content/browser/renderer_host/render_process_host_impl.cc.orig	2025-10-28 14:29:43 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -226,7 +226,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -1126,7 +1126,7 @@ static constexpr size_t kUnknownPlatformProcessLimit =
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1351,7 +1351,7 @@ RenderProcessHostImpl::IOThreadHostImpl::~IOThreadHost
 
 void RenderProcessHostImpl::IOThreadHostImpl::SetPid(
     base::ProcessId child_pid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(child_pid);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
@@ -3459,7 +3459,7 @@ void RenderProcessHostImpl::AppendRendererCommandLine(
             base::TimeTicks::UnixEpoch().since_origin().InMicroseconds()));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Append `kDisableVideoCaptureUseGpuMemoryBuffer` flag if there is no support
   // for NV12 GPU memory buffer.
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled() &&
@@ -3515,6 +3515,8 @@ void RenderProcessHostImpl::PropagateBrowserCommandLin
       switches::kDisableSkiaRuntimeOpts,
       switches::kDisableSpeechAPI,
       switches::kDisableThreadedCompositing,
+      switches::kDisableUnveil,
+      switches::kTrk,
       switches::kDisableV8IdleTasks,
       switches::kDisableVideoCaptureUseGpuMemoryBuffer,
       switches::kDisableWebGLImageChromium,
@@ -5417,7 +5419,7 @@ uint64_t RenderProcessHostImpl::GetPrivateMemoryFootpr
   // - Win: https://crbug.com/707022 .
   uint64_t total_size = 0;
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   total_size = dump->platform_private_footprint->rss_anon_bytes +
                dump->platform_private_footprint->vm_swap_bytes;
 #elif BUILDFLAG(IS_APPLE)
