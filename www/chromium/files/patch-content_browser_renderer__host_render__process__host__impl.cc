--- content/browser/renderer_host/render_process_host_impl.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -206,7 +206,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -1226,7 +1226,7 @@ static constexpr size_t kUnknownPlatformProcessLimit =
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1313,7 +1313,7 @@ class RenderProcessHostImpl::IOThreadHostImpl : public
         return;
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
       ConnectToFontService(std::move(font_receiver));
       return;
@@ -3321,6 +3321,7 @@ void RenderProcessHostImpl::PropagateBrowserCommandLin
     switches::kDisableSpeechAPI,
     switches::kDisableThreadedCompositing,
     switches::kDisableTouchDragDrop,
+    switches::kDisableUnveil,
     switches::kDisableV8IdleTasks,
     switches::kDisableVideoCaptureUseGpuMemoryBuffer,
     switches::kDisableWebGLImageChromium,
