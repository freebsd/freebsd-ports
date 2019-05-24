--- components/crash/content/app/crashpad.cc.orig	2019-04-30 22:22:41 UTC
+++ components/crash/content/app/crashpad.cc
@@ -104,6 +104,12 @@ void InitializeCrashpadImpl(bool initial_client,
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
@@ -124,7 +130,7 @@ void InitializeCrashpadImpl(bool initial_client,
     DCHECK(browser_process || process_type == "Chrome Installer" ||
            process_type == "notification-helper" ||
            process_type == "GCPW Installer" || process_type == "GCPW DLL");
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     DCHECK(browser_process);
 #else
 #error Port.
@@ -192,7 +198,7 @@ void InitializeCrashpadImpl(bool initial_client,
   // other "main, first process" to initialize things. There is no "relauncher"
   // on Windows, so this is synonymous with initial_client.
   const bool should_initialize_database_and_set_upload_policy = initial_client;
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   const bool should_initialize_database_and_set_upload_policy = browser_process;
 #endif
   if (should_initialize_database_and_set_upload_policy) {
@@ -272,7 +278,9 @@ bool GetUploadsEnabled() {
 
 #if !defined(OS_ANDROID)
 void DumpWithoutCrashing() {
+#if !defined(OS_BSD)
   CRASHPAD_SIMULATE_CRASH();
+#endif
 }
 #endif
 
