--- components/crash/content/app/crashpad.h.orig	2019-12-19 16:46:22 UTC
+++ components/crash/content/app/crashpad.h
@@ -22,7 +22,7 @@
 #include <windows.h>
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <signal.h>
 #endif
 
@@ -37,7 +37,7 @@ class CrashReportDatabase;
 
 namespace crash_reporter {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // TODO(jperaza): Remove kEnableCrashpad and IsCrashpadEnabled() when Crashpad
 // is fully enabled on Linux.
 extern const char kEnableCrashpad[];
@@ -146,11 +146,11 @@ void RequestSingleCrashUpload(const std::string& local
 
 void DumpWithoutCrashing();
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // Logs message and immediately crashes the current process without triggering a
 // crash dump.
 void CrashWithoutDumping(const std::string& message);
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // Returns the Crashpad database path, only valid in the browser.
 base::FilePath GetCrashpadDatabasePath();
@@ -188,7 +188,7 @@ bool DumpWithoutCrashingForClient(CrashReporterClient*
 void WhitelistMemoryRange(void* begin, size_t size);
 #endif  // OS_ANDROID
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Install a handler that gets a chance to handle faults before Crashpad. This
 // is used by V8 for trap-based bounds checks.
 void SetFirstChanceExceptionHandler(bool (*handler)(int, siginfo_t*, void*));
@@ -196,7 +196,7 @@ void SetFirstChanceExceptionHandler(bool (*handler)(in
 // Gets the socket and process ID of the Crashpad handler connected to this
 // process, valid if this function returns `true`.
 bool GetHandlerSocket(int* sock, pid_t* pid);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 
 namespace internal {
 
@@ -212,11 +212,11 @@ DWORD WINAPI DumpProcessForHungInputThread(void* param
 
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // Starts the handler process with an initial client connected on fd.
 // Returns `true` on success.
 bool StartHandlerForClient(int fd);
-#endif  // OS_LINUX || OS_ANDROID
+#endif  // OS_LINUX || OS_ANDROID || OS_BSD
 
 // The platform-specific portion of InitializeCrashpad(). On Windows, if
 // |user_data_dir| is non-empty, the user data directory will be passed to the
