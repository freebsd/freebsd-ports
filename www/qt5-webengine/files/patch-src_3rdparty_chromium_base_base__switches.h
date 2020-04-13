--- src/3rdparty/chromium/base/base_switches.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/base/base_switches.h
@@ -37,7 +37,7 @@ extern const char kWaitForDebugger[];
 extern const char kDisableUsbKeyboardDetect[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kDisableDevShmUsage[];
 #endif
 
@@ -50,7 +50,7 @@ extern const char kEnableReachedCodeProfiler[];
 extern const char kOrderfileMemoryOptimization[];
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kEnableThreadInstructionCount[];
 #endif
 
