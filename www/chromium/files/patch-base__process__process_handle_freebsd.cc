--- ./base/process/process_handle_freebsd.cc.orig	2014-04-24 22:36:10.000000000 +0200
+++ ./base/process/process_handle_freebsd.cc	2014-04-24 23:23:41.000000000 +0200
@@ -6,33 +6,35 @@
 
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <unistd.h>
+#include <sys/user.h>
+
+#include "base/logging.h"
 
 namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
-  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
-
-  if (sysctl(mib, arraysize(mib), &info, &length, NULL, 0) < 0)
+  size_t length = sizeof(struct kinfo_proc);
+  int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
+  if (sysctl(mib, 4, &info, &length, NULL, 0) < 0) {
+    DPLOG(ERROR) << "sysctl";
+    return -1;
+  }
+  if (length == 0)
     return -1;
-
   return info.ki_ppid;
 }
 
 FilePath GetProcessExecutablePath(ProcessHandle process) {
   char pathname[PATH_MAX];
-  size_t length;
+  size_t length = sizeof(pathname);
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, process };
-
-  length = sizeof(pathname);
-
-  if (sysctl(mib, arraysize(mib), pathname, &length, NULL, 0) < 0 ||
-      length == 0) {
+  if (sysctl(mib, arraysize(mib), pathname, &length, NULL, 0) < 0) {
+    DPLOG(ERROR) << "sysctl";
     return FilePath();
   }
-
+  if (length == 0)
+    return FilePath();
   return FilePath(std::string(pathname));
 }
 
