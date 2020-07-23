--- chrome/browser/ui/views/first_run_dialog.cc.orig	2020-03-16 18:40:30 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -114,8 +114,10 @@ void FirstRunDialog::Done() {
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   ChangeMetricsReportingStateWithReply(report_crashes_->GetChecked(),
                                        base::Bind(&InitCrashReporterIfEnabled));
+#endif
 
   if (make_default_->GetChecked())
     shell_integration::SetAsDefaultBrowser();
