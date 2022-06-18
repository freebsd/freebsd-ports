--- chrome/browser/ui/views/first_run_dialog.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -34,7 +34,7 @@
 
 namespace {
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void InitCrashReporterIfEnabled(bool enabled) {
   if (!crash_reporter::IsCrashpadEnabled() && enabled)
     breakpad::InitCrashReporter(std::string());
@@ -122,7 +122,7 @@ bool FirstRunDialog::Accept() {
 
 #if BUILDFLAG(IS_MAC)
   ChangeMetricsReportingState(report_crashes_->GetChecked());
-#else
+#elif !BUILDFLAG(IS_BSD)
   ChangeMetricsReportingStateWithReply(
       report_crashes_->GetChecked(),
       base::BindOnce(&InitCrashReporterIfEnabled));
