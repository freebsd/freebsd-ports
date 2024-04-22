--- base/process/process_handle_openbsd.cc.orig	2024-03-22 14:16:19 UTC
+++ base/process/process_handle_openbsd.cc
@@ -3,48 +3,112 @@
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
 
+#include <kvm.h>
+
 namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
-  struct kinfo_proc info;
+  struct kinfo_proc *info;
   size_t length;
+  pid_t ppid;
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process,
                 sizeof(struct kinfo_proc), 0 };
 
   if (sysctl(mib, std::size(mib), NULL, &length, NULL, 0) < 0)
     return -1;
 
-  mib[5] = (length / sizeof(struct kinfo_proc));
+  info = (struct kinfo_proc *)malloc(length);
 
-  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0)
-    return -1;
+  mib[5] = static_cast<int>((length / sizeof(struct kinfo_proc)));
 
-  return info.p_ppid;
+  if (sysctl(mib, std::size(mib), info, &length, NULL, 0) < 0) {
+    ppid = -1;
+    goto out;
+  }
+
+  ppid = info->p_ppid;
+
+out:
+  free(info);
+  return ppid;
 }
 
 FilePath GetProcessExecutablePath(ProcessHandle process) {
-  struct kinfo_proc kp;
+  struct kinfo_file *files;
+  kvm_t *kd = NULL;
+  char errbuf[_POSIX2_LINE_MAX];
+  char **retvalargs, *cpath, retval[PATH_MAX];
+  int cnt;
   size_t len;
-  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process,
-                sizeof(struct kinfo_proc), 0 };
+  char *tokens[2];
+  struct stat sb;
+  FilePath *result = nullptr;
 
-  if (sysctl(mib, std::size(mib), NULL, &len, NULL, 0) == -1)
-    return FilePath();
-  mib[5] = (len / sizeof(struct kinfo_proc));
-  if (sysctl(mib, std::size(mib), &kp, &len, NULL, 0) < 0)
-    return FilePath();
-  if ((kp.p_flag & P_SYSTEM) != 0)
-    return FilePath();
-  if (strcmp(kp.p_comm, "chrome") == 0)
-    return FilePath(kp.p_comm);
+  int mib[] = { CTL_KERN, KERN_PROC_ARGS, process, KERN_PROC_ARGV };
 
-  return FilePath();
+  if ((cpath = getenv("CHROME_EXE_PATH")) != NULL)
+    *result = FilePath(cpath);
+  else
+    *result = FilePath("/usr/local/chrome/chrome");
+
+  if (sysctl(mib, std::size(mib), NULL, &len, NULL, 0) != -1) {
+    retvalargs = static_cast<char**>(malloc(len));
+    if (!retvalargs)
+      return *result;
+
+    if (sysctl(mib, std::size(mib), retvalargs, &len, NULL, 0) < 0) {
+      free(retvalargs);
+      return *result;
+    }
+
+    if ((*tokens = strtok(retvalargs[0], ":")) == NULL) {
+      free(retvalargs);
+      return *result;
+    }
+
+    free(retvalargs);
+
+    if (tokens[0] == NULL)
+      return *result;
+
+    if (realpath(tokens[0], retval) == NULL)
+      return *result;
+
+    if (stat(retval, &sb) < 0)
+      return *result;
+
+    if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES,
+         errbuf)) == NULL)
+      return *result;
+
+    if ((files = kvm_getfiles(kd, KERN_FILE_BYPID, process,
+        sizeof(struct kinfo_file), &cnt)) == NULL) {
+      kvm_close(kd);
+      return *result;
+    }
+
+    for (int i = 0; i < cnt; i++) {
+      if (files[i].fd_fd == KERN_FILE_TEXT &&
+          files[i].va_fsid == static_cast<uint32_t>(sb.st_dev) &&
+          files[i].va_fileid == sb.st_ino) {
+            kvm_close(kd);
+            *result = FilePath(retval);
+      }
+    }
+  }
+
+  return *result;
 }
 
 }  // namespace base
