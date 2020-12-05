--- base/linux_util.cc.orig	2020-11-13 06:36:34 UTC
+++ base/linux_util.cc
@@ -15,6 +15,7 @@
 
 #include <iomanip>
 #include <memory>
+#include <sstream>
 
 #include "base/files/dir_reader_posix.h"
 #include "base/files/file_util.h"
@@ -78,6 +79,9 @@ class DistroNameGetter {
  public:
   DistroNameGetter() {
     static const char* const kFilesToCheck[] = {"/etc/os-release",
+#if defined(OS_BSD)
+	                                        "/usr/local/etc/os-release",
+#endif
                                                 "/usr/lib/os-release"};
     for (const char* file : kFilesToCheck) {
       if (ReadDistroFromOSReleaseFile(file))
@@ -134,6 +138,9 @@ void SetLinuxDistro(const std::string& distro) {
 }
 
 bool GetThreadsForProcess(pid_t pid, std::vector<pid_t>* tids) {
+#if defined(OS_BSD)
+  return false;
+#else
   // 25 > strlen("/proc//task") + strlen(std::to_string(INT_MAX)) + 1 = 22
   char buf[25];
   strings::SafeSPrintf(buf, "/proc/%d/task", pid);
@@ -153,6 +160,7 @@ bool GetThreadsForProcess(pid_t pid, std::vector<pid_t
   }
 
   return true;
+#endif
 }
 
 pid_t FindThreadIDWithSyscall(pid_t pid, const std::string& expected_data,
