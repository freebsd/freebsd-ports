--- chrome/browser/ui/views/first_run_dialog.cc.orig	2014-10-10 08:54:11 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -118,12 +118,16 @@
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   if (report_crashes_ && report_crashes_->checked()) {
     if (GoogleUpdateSettings::SetCollectStatsConsent(true))
       breakpad::InitCrashReporter(std::string());
-  } else {
+  } else
+#else
+  {
     GoogleUpdateSettings::SetCollectStatsConsent(false);
   }
+#endif
 
   if (make_default_ && make_default_->checked())
     ShellIntegration::SetAsDefaultBrowser();
