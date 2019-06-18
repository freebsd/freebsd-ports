--- chrome/browser/ui/views/first_run_dialog.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -37,8 +37,10 @@
 namespace {
 
 void InitCrashReporterIfEnabled(bool enabled) {
+#if !defined(OS_BSD)
   if (enabled)
     breakpad::InitCrashReporter(std::string());
+#endif
 }
 
 }  // namespace
@@ -111,8 +113,10 @@ views::View* FirstRunDialog::CreateExtraView() {
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   ChangeMetricsReportingStateWithReply(report_crashes_->checked(),
                                        base::Bind(&InitCrashReporterIfEnabled));
+#endif
 
   if (make_default_->checked())
     shell_integration::SetAsDefaultBrowser();
