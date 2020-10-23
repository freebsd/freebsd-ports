--- base/process/launch_posix.cc.orig	2020-09-08 19:13:57 UTC
+++ base/process/launch_posix.cc
@@ -65,6 +65,7 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#pragma weak environ
 extern char** environ;
 
 namespace base {
@@ -228,6 +229,28 @@
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
