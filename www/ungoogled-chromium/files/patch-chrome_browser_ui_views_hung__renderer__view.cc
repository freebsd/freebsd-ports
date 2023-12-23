--- chrome/browser/ui/views/hung_renderer_view.cc.orig	2023-12-23 12:33:28 UTC
+++ chrome/browser/ui/views/hung_renderer_view.cc
@@ -405,7 +405,7 @@ void HungRendererDialogView::ForceCrashHungRenderer() 
   content::RenderProcessHost* rph =
       hung_pages_table_model_->GetRenderWidgetHost()->GetProcess();
   if (rph) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
