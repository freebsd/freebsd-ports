--- chrome/browser/ui/views/first_run_dialog.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -114,9 +114,11 @@ void FirstRunDialog::Done() {
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   ChangeMetricsReportingStateWithReply(
       report_crashes_->GetChecked(),
       base::BindRepeating(&InitCrashReporterIfEnabled));
+#endif
 
   if (make_default_->GetChecked())
     shell_integration::SetAsDefaultBrowser();
