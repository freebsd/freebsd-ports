--- components/crash/content/app/crashpad.cc.orig	2018-07-19 00:30:58.065324000 +0200
+++ components/crash/content/app/crashpad.cc	2018-07-19 00:32:11.350482000 +0200
@@ -119,7 +119,7 @@
     // as processed by the backend.
     DCHECK(browser_process || process_type == "Chrome Installer" ||
            process_type == "notification-helper");
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     DCHECK(browser_process);
 #else
 #error Port.
@@ -184,7 +184,7 @@
   // other "main, first process" to initialize things. There is no "relauncher"
   // on Windows, so this is synonymous with initial_client.
   const bool should_initialize_database_and_set_upload_policy = initial_client;
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   const bool should_initialize_database_and_set_upload_policy = browser_process;
 #endif
   if (should_initialize_database_and_set_upload_policy) {
@@ -253,7 +253,11 @@
 }
 
 void DumpWithoutCrashing() {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+#else
   CRASHPAD_SIMULATE_CRASH();
+#endif
 }
 
 void GetReports(std::vector<Report>* reports) {
