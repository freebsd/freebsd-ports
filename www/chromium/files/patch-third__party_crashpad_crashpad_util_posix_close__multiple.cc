--- third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2020-11-13 06:37:02 UTC
+++ third_party/crashpad/crashpad/util/posix/close_multiple.cc
@@ -181,11 +181,37 @@ void CloseMultipleNowOrOnExec(int fd, int preserve_fd)
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
