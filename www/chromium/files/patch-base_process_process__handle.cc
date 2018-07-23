--- base/process/process_handle.cc.orig	2018-07-19 22:31:30.212555000 +0200
+++ base/process/process_handle.cc	2018-07-19 22:32:27.185612000 +0200
@@ -39,7 +39,7 @@
   return g_unique_id;
 }
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
 void InitUniqueIdForProcessInPidNamespace(ProcessId pid_outside_of_namespace) {
   g_unique_id = MangleProcessId(pid_outside_of_namespace);
