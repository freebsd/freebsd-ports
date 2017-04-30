--- chrome/browser/ui/views/first_run_dialog.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -40,8 +40,10 @@ using views::GridLayout;
 namespace {
 
 void InitCrashReporterIfEnabled(bool enabled) {
+#ifndef OS_BSD
   if (enabled)
     breakpad::InitCrashReporter(std::string());
+#endif
 }
 
 }  // namespace
@@ -121,8 +123,10 @@ views::View* FirstRunDialog::CreateExtra
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   ChangeMetricsReportingStateWithReply(report_crashes_->checked(),
                                        base::Bind(&InitCrashReporterIfEnabled));
+#endif
 
   if (make_default_->checked())
     shell_integration::SetAsDefaultBrowser();
