--- third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2020-09-08 19:14:24 UTC
+++ third_party/crashpad/crashpad/util/posix/close_multiple.cc
@@ -31,7 +31,7 @@
 #include "util/file/directory_reader.h"
 #include "util/misc/implicit_cast.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include <sys/sysctl.h>
 #endif
 
@@ -72,7 +72,7 @@
 // This is an advantage over looping over all possible file descriptors, because
 // no attempt needs to be made to close file descriptors that are not open.
 bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, int preserve_fd) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   static constexpr char kFDDir[] = "/dev/fd";
 #elif defined(OS_LINUX) || defined(OS_ANDROID)
   static constexpr char kFDDir[] = "/proc/self/fd";
@@ -146,7 +146,7 @@
   // while the system is running, but it’s still a better upper bound than the
   // current RLIMIT_NOFILE value.
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // See 10.11.6 xnu-3248.60.10/bsd/kern/kern_resource.c maxfilesperproc,
   // referenced by dosetrlimit().
   int oid[] = {CTL_KERN, KERN_MAXFILESPERPROC};
@@ -180,11 +180,37 @@
   }
 #endif
 
+#if defined(OS_BSD)
+  // If preserve_fd is in the space to be freed, copy it down.
+  bool copied = false;
+  if (preserve_fd >= fd) {
+    if (preserve_fd > fd) {
+      int rv = dup2(preserve_fd, fd);
+      if (rv != 0)
+	PLOG(WARNING) << "dup2";
+      copied = true;
+    }
+    fd++;
+  }
+  // Cloexec is only used for MACOS...
+  closefrom(fd);
+  // Put it back.
+  if (copied) {
+    fd--;
+    int rv = dup2(fd, preserve_fd);
+    if (rv != 0)
+      PLOG(WARNING) << "dup2";
+    rv = IGNORE_EINTR(close(fd));
+    if (rv != 0)
+      PLOG(WARNING) << "close";
+  }
+#else
   for (int entry_fd = fd; entry_fd < max_fd; ++entry_fd) {
     if (entry_fd != preserve_fd) {
       CloseNowOrOnExec(entry_fd, true);
     }
   }
+#endif
 }
 
 }  // namespace crashpad
