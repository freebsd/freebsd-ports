--- chrome/browser/ui/views/hung_renderer_view.cc.orig	2020-05-13 18:40:25 UTC
+++ chrome/browser/ui/views/hung_renderer_view.cc
@@ -425,7 +425,7 @@ void HungRendererDialogView::ForceCrashHungRenderer() 
   content::RenderProcessHost* rph =
       hung_pages_table_model_->GetRenderWidgetHost()->GetProcess();
   if (rph) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
