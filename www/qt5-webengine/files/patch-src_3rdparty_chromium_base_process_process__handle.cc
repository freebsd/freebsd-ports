--- src/3rdparty/chromium/base/process/process_handle.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/process/process_handle.cc
@@ -39,7 +39,7 @@ uint32_t GetUniqueIdForProcess() {
   return g_unique_id;
 }
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
 void InitUniqueIdForProcessInPidNamespace(ProcessId pid_outside_of_namespace) {
   g_unique_id = MangleProcessId(pid_outside_of_namespace);
