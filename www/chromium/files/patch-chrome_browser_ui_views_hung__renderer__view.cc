--- chrome/browser/ui/views/hung_renderer_view.cc.orig	2019-12-16 21:50:43 UTC
+++ chrome/browser/ui/views/hung_renderer_view.cc
@@ -379,7 +379,7 @@ bool HungRendererDialogView::Cancel() {
   content::RenderProcessHost* rph =
       hung_pages_table_model_->GetRenderWidgetHost()->GetProcess();
   if (rph) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
