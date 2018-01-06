--- src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.cc
@@ -368,11 +368,11 @@ SiteProcessMap* GetSiteProcessMapForBrow
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
@@ -395,7 +395,7 @@ class RendererSandboxedProcessLauncherDe
     return GetContentClient()->browser()->PreSpawnRenderer(policy);
   }
 
-#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();
@@ -635,7 +635,7 @@ void RenderProcessHost::SetMaxRendererPr
   g_max_renderer_count_override = count;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void RenderProcessHostImpl::EarlyZygoteLaunch() {
   DCHECK(!g_render_zygote);
@@ -645,7 +645,7 @@ void RenderProcessHostImpl::EarlyZygoteL
   ZygoteHostImpl::GetInstance()->SetRendererSandboxStatus(
       (*GetGenericZygote())->GetSandboxStatus());
 }
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 RenderProcessHostImpl::RenderProcessHostImpl(
     BrowserContext* browser_context,
@@ -788,7 +788,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #else
