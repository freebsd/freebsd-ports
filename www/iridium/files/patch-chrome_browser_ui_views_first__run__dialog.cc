--- chrome/browser/ui/views/first_run_dialog.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -40,8 +40,10 @@ using views::GridLayout;
 namespace {
 
 void InitCrashReporterIfEnabled(bool enabled) {
+#if !defined(OS_BSD)
   if (enabled)
     breakpad::InitCrashReporter(std::string());
+#endif
 }
 
 }  // namespace
@@ -120,8 +122,10 @@ views::View* FirstRunDialog::CreateExtraView() {
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   ChangeMetricsReportingStateWithReply(report_crashes_->checked(),
                                        base::Bind(&InitCrashReporterIfEnabled));
+#endif
 
   if (make_default_->checked())
     shell_integration::SetAsDefaultBrowser();
