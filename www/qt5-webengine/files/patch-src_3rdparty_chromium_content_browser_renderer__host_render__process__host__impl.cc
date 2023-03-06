--- src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.cc
@@ -234,7 +234,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 #include <sys/time.h>
 
@@ -1232,7 +1232,7 @@ size_t GetPlatformProcessLimit() {
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1243,7 +1243,7 @@ size_t GetPlatformProcessLimit() {
 #else
   // TODO(https://crbug.com/104689): Implement on other platforms.
   return kUnknownPlatformProcessLimit;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
@@ -1325,7 +1325,7 @@ void RenderProcessHostImpl::IOThreadHostImpl::BindHost
       return;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
@@ -1751,7 +1751,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MAC)
@@ -3323,7 +3323,7 @@ void RenderProcessHostImpl::PropagateBrowserCommandLin
 #if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)
     switches::kDisableDevShmUsage,
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)) || defined(OS_BSD)
     switches::kEnableAcceleratedVideoDecode,
 #endif
 #if defined(OS_MAC)
