--- src/3rdparty/chromium/base/base_switches.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/base/base_switches.cc
@@ -114,7 +114,7 @@ const char kWaitForDebugger[] = "wait-for-debugger";
 const char kDisableUsbKeyboardDetect[]      = "disable-usb-keyboard-detect";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // The /dev/shm partition is too small in certain VM environments, causing
 // Chrome to fail or crash (see http://crbug.com/715363). Use this flag to
 // work-around this issue (a temporary directory will always be used to create
@@ -135,7 +135,7 @@ const char kEnableCrashReporterForTesting[] =
 const char kEnableReachedCodeProfiler[] = "enable-reached-code-profiler";
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Controls whether or not retired instruction counts are surfaced for threads
 // in trace events on Linux.
 //
