--- chrome/browser/first_run/first_run_internal_posix.cc.orig	2018-02-24 16:25:09.000000000 +0100
+++ chrome/browser/first_run/first_run_internal_posix.cc	2018-03-03 21:26:08.717035000 +0100
@@ -34,7 +34,7 @@
 namespace internal {
 namespace {
 
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // Returns whether the first run dialog should be shown. This is only true for
 // certain builds, and only if the user has not already set preferences. In a
 // real, official-build first run, initializes the default metrics reporting if
@@ -80,7 +80,7 @@
 }  // namespace
 
 void DoPostImportPlatformSpecificTasks(Profile* profile) {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (!ShouldShowFirstRunDialog())
     return;
 
