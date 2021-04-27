--- base/process/launch_posix.cc.orig	2021-04-14 18:40:48 UTC
+++ base/process/launch_posix.cc
@@ -59,12 +59,14 @@
 #if defined(OS_FREEBSD)
 #include <sys/event.h>
 #include <sys/ucontext.h>
+#include <sys/procctl.h>
 #endif
 
 #if defined(OS_APPLE)
 #error "macOS should use launch_mac.cc"
 #endif
 
+#pragma weak environ
 extern char** environ;
 
 namespace base {
@@ -221,6 +223,28 @@ void CloseSuperfluousFds(const base::InjectiveMultimap
   DirReaderPosix fd_dir(kFDDir);
   if (!fd_dir.IsValid()) {
     // Fallback case: Try every possible fd.
+
+#if defined(OS_FREEBSD)
+    // CEM: blast away most of the range with closefrom().  A common use case
+    // of this function only maps STDIN/STDOUT/STDERR and closefrom(3) is much
+    // cheaper than x00,000 close(2) invocations with a high RLIMIT_NOFILE.
+    //
+    // In the other caller, it is still very likely that the fds we care about
+    // are in relatively low number space and we can save hundreds of thousands
+    // of syscalls.
+    int max_valid_fd = -1;
+    for (size_t j = 0; j < saved_mapping.size(); j++) {
+      int fd = saved_mapping[j].dest;
+      if (fd > max_valid_fd)
+	max_valid_fd = fd;
+    }
+    if (max_valid_fd < STDERR_FILENO)
+      max_valid_fd = STDERR_FILENO;
+
+    closefrom(max_valid_fd + 1);
+    max_fds = static_cast<size_t>(max_valid_fd) + 1;
+#endif
+
     for (size_t i = 0; i < max_fds; ++i) {
       const int fd = static_cast<int>(i);
       if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
@@ -444,22 +468,32 @@ Process LaunchProcess(const std::vector<std::string>& 
 
     // Set NO_NEW_PRIVS by default. Since NO_NEW_PRIVS only exists in kernel
     // 3.5+, do not check the return value of prctl here.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_FREEBSD)
 #ifndef PR_SET_NO_NEW_PRIVS
 #define PR_SET_NO_NEW_PRIVS 38
 #endif
+#if !defined(OS_FREEBSD)
     if (!options.allow_new_privs) {
       if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0) && errno != EINVAL) {
         // Only log if the error is not EINVAL (i.e. not supported).
         RAW_LOG(FATAL, "prctl(PR_SET_NO_NEW_PRIVS) failed");
       }
     }
+#endif
 
     if (options.kill_on_parent_death) {
+#if defined(OS_FREEBSD)
+      int procctl_value = SIGKILL;
+      if (procctl(P_PID, 0, PROC_PDEATHSIG_CTL, &procctl_value)) {
+        RAW_LOG(ERROR, "procctl(PROC_PDEATHSIG_CTL) failed");
+        _exit(127);
+      }
+#else
       if (prctl(PR_SET_PDEATHSIG, SIGKILL) != 0) {
         RAW_LOG(ERROR, "prctl(PR_SET_PDEATHSIG) failed");
         _exit(127);
       }
+#endif
     }
 #endif
 
