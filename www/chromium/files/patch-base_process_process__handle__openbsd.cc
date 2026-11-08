--- base/process/process_handle_openbsd.cc.orig	2026-09-25 15:26:43 UTC
+++ base/process/process_handle_openbsd.cc
@@ -3,8 +3,13 @@
 // found in the LICENSE file.
 
 #include "base/process/process_handle.h"
+#include "base/files/file_util.h"
 
 #include <stddef.h>
+#include <stdlib.h>
+#include <sys/param.h>
+#include <sys/proc.h>
+#include <sys/stat.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -12,8 +17,9 @@
 namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
-  struct kinfo_proc info;
+  struct kinfo_proc *info;
   size_t length;
+  pid_t ppid;
   int mib[] = {
       CTL_KERN, KERN_PROC, KERN_PROC_PID, process, sizeof(struct kinfo_proc),
       0};
@@ -22,37 +28,39 @@ ProcessId GetParentProcessId(ProcessHandle process) {
     return -1;
   }
 
-  mib[5] = (length / sizeof(struct kinfo_proc));
+  info = (struct kinfo_proc *)malloc(length);
 
-  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
-    return -1;
+  mib[5] = static_cast<int>((length / sizeof(struct kinfo_proc)));
+
+  if (sysctl(mib, std::size(mib), info, &length, NULL, 0) < 0) {
+    ppid = -1;
+    goto out;
   }
 
-  return info.p_ppid;
+  ppid = info->p_ppid;
+
+out:
+  free(info);
+  return ppid;
 }
 
 FilePath GetProcessExecutablePath(ProcessHandle process) {
-  struct kinfo_proc kp;
-  size_t len;
-  int mib[] = {
-      CTL_KERN, KERN_PROC, KERN_PROC_PID, process, sizeof(struct kinfo_proc),
-      0};
-
-  if (sysctl(mib, std::size(mib), NULL, &len, NULL, 0) == -1) {
+  FilePath result;
+#if (OpenBSD >= 202610)
+  char execpath[PATH_MAX];
+  if (getexecpath(execpath, sizeof(execpath)) != 0) {
     return FilePath();
+  } 
+  result = FilePath(execpath);
+#else
+  char *cpath;
+  if ((cpath = getenv("CHROME_EXE_PATH")) != NULL) {
+    result = FilePath(cpath);
+  } else {
+    result = FilePath("/usr/local/chrome/chrome");
   }
-  mib[5] = (len / sizeof(struct kinfo_proc));
-  if (sysctl(mib, std::size(mib), &kp, &len, NULL, 0) < 0) {
-    return FilePath();
-  }
-  if ((kp.p_flag & P_SYSTEM) != 0) {
-    return FilePath();
-  }
-  if (strcmp(kp.p_comm, "chrome") == 0) {
-    return FilePath(kp.p_comm);
-  }
-
-  return FilePath();
+#endif
+  return result;
 }
 
 }  // namespace base
