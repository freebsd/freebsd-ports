--- base/process_util_freebsd.cc.orig	2013-08-19 02:53:01.000000000 +0300
+++ base/process_util_freebsd.cc	2013-08-31 13:54:23.000000000 +0300
@@ -18,7 +18,7 @@
 #include <unistd.h>
 
 #include "base/logging.h"
-#include "base/string_tokenizer.h"
+#include "base/strings/string_tokenizer.h"
 #include "base/strings/string_number_conversions.h"
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
@@ -28,27 +28,27 @@
 
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
 
