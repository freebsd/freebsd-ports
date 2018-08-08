--- components/crash/content/app/crashpad.cc.orig	2018-08-01 00:08:38.000000000 +0200
+++ components/crash/content/app/crashpad.cc	2018-08-05 12:57:33.862455000 +0200
@@ -101,6 +101,12 @@
                             const std::string& user_data_dir,
                             const base::FilePath& exe_path,
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
@@ -119,7 +125,7 @@
     // as processed by the backend.
     DCHECK(browser_process || process_type == "Chrome Installer" ||
            process_type == "notification-helper");
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     DCHECK(browser_process);
 #else
 #error Port.
@@ -184,7 +190,7 @@
   // other "main, first process" to initialize things. There is no "relauncher"
   // on Windows, so this is synonymous with initial_client.
   const bool should_initialize_database_and_set_upload_policy = initial_client;
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   const bool should_initialize_database_and_set_upload_policy = browser_process;
 #endif
   if (should_initialize_database_and_set_upload_policy) {
@@ -253,7 +259,9 @@
 }
 
 void DumpWithoutCrashing() {
+#if !defined(OS_BSD)
   CRASHPAD_SIMULATE_CRASH();
+#endif
 }
 
 void GetReports(std::vector<Report>* reports) {
