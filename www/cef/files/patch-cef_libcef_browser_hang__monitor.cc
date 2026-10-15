--- cef/libcef/browser/hang_monitor.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/hang_monitor.cc
@@ -21,7 +21,7 @@ namespace {
 void ForceCrashHungRenderer(content::RenderWidgetHost* render_widget_host) {
   content::RenderProcessHost* rph = render_widget_host->GetProcess();
   if (rph) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
