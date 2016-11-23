--- chrome/browser/ui/views/first_run_dialog.cc.orig	2016-10-06 04:02:13.000000000 +0300
+++ chrome/browser/ui/views/first_run_dialog.cc	2016-10-15 10:10:45.850050000 +0300
@@ -35,8 +35,10 @@
 namespace {
 
 void InitCrashReporterIfEnabled(bool enabled) {
+#ifndef OS_BSD
   if (enabled)
     breakpad::InitCrashReporter(std::string());
+#endif
 }
 
 }  // namespace
