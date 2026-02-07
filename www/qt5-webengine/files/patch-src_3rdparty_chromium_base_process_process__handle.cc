--- src/3rdparty/chromium/base/process/process_handle.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/process/process_handle.cc
@@ -30,7 +30,7 @@ UniqueProcId GetUniqueIdForProcess() {
              : UniqueProcId(GetCurrentProcId());
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 
 void InitUniqueIdForProcessInPidNamespace(ProcessId pid_outside_of_namespace) {
   DCHECK(pid_outside_of_namespace != kNullProcessId);
