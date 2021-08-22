--- base/process/process_handle_freebsd.cc.orig	2021-07-19 18:45:05 UTC
+++ base/process/process_handle_freebsd.cc
@@ -3,7 +3,6 @@
 // found in the LICENSE file.
 
 #include "base/process/process_handle.h"
-#include "base/stl_util.h"
 
 #include <limits.h>
 #include <stddef.h>
@@ -12,14 +11,20 @@
 #include <sys/user.h>
 #include <unistd.h>
 
+#include "base/files/file_path.h"
+#include "base/stl_util.h"
+
 namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
 
   if (sysctl(mib, base::size(mib), &info, &length, NULL, 0) < 0)
+    return -1;
+
+  if (length < sizeof(struct kinfo_proc))
     return -1;
 
   return info.ki_ppid;
