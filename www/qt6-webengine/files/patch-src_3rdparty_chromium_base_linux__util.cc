--- src/3rdparty/chromium/base/linux_util.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/linux_util.cc
@@ -15,6 +15,7 @@
 
 #include <iomanip>
 #include <memory>
+#include <sstream>
 
 #include "base/base_export.h"
 #include "base/files/dir_reader_posix.h"
@@ -135,6 +136,9 @@ bool GetThreadsForProcess(pid_t pid, std::vector<pid_t
 }
 
 bool GetThreadsForProcess(pid_t pid, std::vector<pid_t>* tids) {
+#if defined(OS_BSD)
+  return false;
+#else
   // 25 > strlen("/proc//task") + strlen(std::to_string(INT_MAX)) + 1 = 22
   char buf[25];
   strings::SafeSPrintf(buf, "/proc/%d/task", pid);
@@ -154,6 +158,7 @@ bool GetThreadsForProcess(pid_t pid, std::vector<pid_t
   }
 
   return true;
+#endif
 }
 
 pid_t FindThreadIDWithSyscall(pid_t pid, const std::string& expected_data,
