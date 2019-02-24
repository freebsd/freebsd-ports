--- components/crash/content/app/crashpad.cc.orig	2019-01-30 02:17:53.000000000 +0100
+++ components/crash/content/app/crashpad.cc	2019-01-31 23:31:14.742328000 +0100
@@ -102,6 +102,12 @@
                             const base::FilePath& exe_path,
                             const std::vector<std::string>& initial_arguments,
                             bool embedded_handler) {
+
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return;
+#endif
+
   static bool initialized = false;
   DCHECK(!initialized);
   initialized = true;
@@ -121,7 +127,7 @@
     DCHECK(browser_process || process_type == "Chrome Installer" ||
            process_type == "notification-helper" ||
            process_type == "GCPW Installer" || process_type == "GCPW DLL");
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     DCHECK(browser_process);
 #else
 #error Port.
@@ -186,7 +192,7 @@
   // other "main, first process" to initialize things. There is no "relauncher"
   // on Windows, so this is synonymous with initial_client.
   const bool should_initialize_database_and_set_upload_policy = initial_client;
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   const bool should_initialize_database_and_set_upload_policy = browser_process;
 #endif
   if (should_initialize_database_and_set_upload_policy) {
@@ -265,7 +271,9 @@
 }
 
 void DumpWithoutCrashing() {
+#if !defined(OS_BSD)
   CRASHPAD_SIMULATE_CRASH();
+#endif
 }
 
 void GetReports(std::vector<Report>* reports) {
