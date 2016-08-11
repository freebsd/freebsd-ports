--- content/browser/renderer_host/render_process_host_impl.cc.orig	2016-05-20 17:18:26 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -366,7 +366,7 @@ SiteProcessMap* GetSiteProcessMapForBrow
   return map;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // This static member variable holds the zygote communication information for
 // the renderer.
 ZygoteHandle g_render_zygote;
@@ -399,7 +399,7 @@ class RendererSandboxedProcessLauncherDe
   }
 
 #elif defined(OS_POSIX)
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();
@@ -539,7 +539,7 @@ void RenderProcessHost::SetMaxRendererPr
   g_max_renderer_count_override = count;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void RenderProcessHostImpl::EarlyZygoteLaunch() {
   DCHECK(!g_render_zygote);
