--- chrome/browser/first_run/first_run_internal_posix.cc.orig	2017-04-24 14:40:29 UTC
+++ chrome/browser/first_run/first_run_internal_posix.cc
@@ -25,7 +25,7 @@ namespace first_run {
 namespace internal {
 
 void DoPostImportPlatformSpecificTasks(Profile* profile) {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   base::FilePath local_state_path;
   PathService::Get(chrome::FILE_LOCAL_STATE, &local_state_path);
   bool local_state_file_exists = base::PathExists(local_state_path);
