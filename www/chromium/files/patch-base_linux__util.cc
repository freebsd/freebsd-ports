--- base/linux_util.cc.orig	2023-12-10 06:10:27 UTC
+++ base/linux_util.cc
@@ -15,6 +15,7 @@
 
 #include <iomanip>
 #include <memory>
+#include <sstream>
 
 #include "base/base_export.h"
 #include "base/files/dir_reader_posix.h"
@@ -153,10 +154,14 @@ void SetLinuxDistro(const std::string& distro) {
 }
 
 bool GetThreadsForProcess(pid_t pid, std::vector<pid_t>* tids) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   // 25 > strlen("/proc//task") + strlen(std::to_string(INT_MAX)) + 1 = 22
   char buf[25];
   strings::SafeSPrintf(buf, "/proc/%d/task", pid);
   return GetThreadsFromProcessDir(buf, tids);
+#endif
 }
 
 bool GetThreadsForCurrentProcess(std::vector<pid_t>* tids) {
