--- ./chrome/browser/ui/views/first_run_dialog.cc.orig	2014-08-12 21:01:38.000000000 +0200
+++ ./chrome/browser/ui/views/first_run_dialog.cc	2014-08-13 09:56:56.000000000 +0200
@@ -124,12 +124,16 @@
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
