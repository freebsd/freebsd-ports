--- content/browser/renderer_host/render_process_host_impl.cc.orig	2020-05-13 18:40:31 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -242,7 +242,7 @@
 #include "content/browser/gpu/gpu_data_manager_impl.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/resource.h>
 #include <sys/time.h>
 
@@ -1199,7 +1199,7 @@ static constexpr size_t kUnknownPlatformProcessLimit =
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1210,7 +1210,7 @@ size_t GetPlatformProcessLimit() {
 #else
   // TODO(https://crbug.com/104689): Implement on other platforms.
   return kUnknownPlatformProcessLimit;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
@@ -1304,7 +1304,7 @@ class RenderProcessHostImpl::IOThreadHostImpl
         return;
     }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
       ConnectToFontService(std::move(font_receiver));
       return;
@@ -1724,7 +1724,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MACOSX)
