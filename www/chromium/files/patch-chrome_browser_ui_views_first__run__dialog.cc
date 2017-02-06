--- chrome/browser/ui/views/first_run_dialog.cc.orig	2017-01-26 00:49:09 UTC
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
