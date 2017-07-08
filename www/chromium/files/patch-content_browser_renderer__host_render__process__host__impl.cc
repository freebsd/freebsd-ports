--- content/browser/renderer_host/render_process_host_impl.cc.orig	2017-06-15 21:03:05.000000000 +0200
+++ content/browser/renderer_host/render_process_host_impl.cc	2017-06-18 13:40:02.058069000 +0200
@@ -381,11 +381,11 @@
   return map;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // This static member variable holds the zygote communication information for
 // the renderer.
 ZygoteHandle g_render_zygote;
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 // NOTE: changes to this class need to be reviewed by the security team.
 class RendererSandboxedProcessLauncherDelegate
@@ -408,7 +408,7 @@
     return GetContentClient()->browser()->PreSpawnRenderer(policy);
   }
 
-#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();
@@ -647,7 +647,7 @@
   g_max_renderer_count_override = count;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void RenderProcessHostImpl::EarlyZygoteLaunch() {
   DCHECK(!g_render_zygote);
@@ -657,7 +657,7 @@
   ZygoteHostImpl::GetInstance()->SetRendererSandboxStatus(
       (*GetGenericZygote())->GetSandboxStatus());
 }
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 RenderProcessHostImpl::RenderProcessHostImpl(
     BrowserContext* browser_context,
@@ -807,7 +807,7 @@
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #else
@@ -1551,7 +1551,6 @@
 
   --visible_widgets_;
   if (visible_widgets_ == 0) {
-    DCHECK(!is_process_backgrounded_);
     UpdateProcessPriority();
   }
 }
