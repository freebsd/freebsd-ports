--- content/browser/renderer_host/render_process_host_impl.cc.orig	2021-04-20 18:58:32 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -227,7 +227,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 #include <sys/time.h>
 
@@ -1324,7 +1324,7 @@ static constexpr size_t kUnknownPlatformProcessLimit =
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1335,7 +1335,7 @@ size_t GetPlatformProcessLimit() {
 #else
   // TODO(https://crbug.com/104689): Implement on other platforms.
   return kUnknownPlatformProcessLimit;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 }
 #endif  // !defined(OS_ANDROID) && !BUILDFLAG(IS_CHROMEOS_ASH)
 
@@ -1409,7 +1409,7 @@ class RenderProcessHostImpl::IOThreadHostImpl : public
         return;
     }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
       ConnectToFontService(std::move(font_receiver));
       return;
@@ -1811,7 +1811,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MAC)
@@ -3225,8 +3225,8 @@ void RenderProcessHostImpl::PropagateBrowserCommandLin
     switches::kDisableInProcessStackTraces,
     sandbox::policy::switches::kDisableSeccompFilterSandbox,
     sandbox::policy::switches::kNoSandbox,
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
-    !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+    !BUILDFLAG(IS_CHROMEOS_LACROS))
     switches::kDisableDevShmUsage,
 #endif
 #if defined(OS_MAC)
@@ -4868,6 +4868,8 @@ void RenderProcessHostImpl::OnProcessLaunched() {
     // TODO(https://crbug.com/875933): Fix initial priority on Android to
     // reflect |priority_.is_background()|.
     DCHECK_EQ(blink::kLaunchingProcessIsBackgrounded, !priority_.visible);
+#elif defined(OS_BSD)
+    priority_.visible = true;
 #else
     priority_.visible =
         !child_process_launcher_->GetProcess().IsProcessBackgrounded();
