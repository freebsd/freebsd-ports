--- content/zygote/zygote_main_linux.cc.orig	2012-08-28 07:17:58.000000000 +0300
+++ content/zygote/zygote_main_linux.cc	2012-08-28 07:57:49.000000000 +0300
@@ -45,6 +45,9 @@
 #include <sys/signal.h>
 #else
 #include <signal.h>
+#if defined(OS_FREEBSD)
+#include <sys/wait.h>
+#endif
 #endif
 
 namespace content {
@@ -153,7 +156,7 @@
 static LocaltimeRFunction g_libc_localtime64_r;
 
 // http://crbug.com/123263, see below.
-#if !defined(ADDRESS_SANITIZER)
+#if !defined(ADDRESS_SANITIZER) && !defined(OS_BSD)
 static pthread_once_t g_libc_file_io_funcs_guard = PTHREAD_ONCE_INIT;
 static FopenFunction g_libc_fopen;
 static FopenFunction g_libc_fopen64;
@@ -269,7 +272,7 @@
 // TODO(sergeyu): Currently this code doesn't work properly under ASAN
 // - it crashes content_unittests. Make sure it works properly and
 // enable it here. http://crbug.com/123263
-#if !defined(ADDRESS_SANITIZER)
+#if !defined(ADDRESS_SANITIZER) && !defined(OS_BSD)
 
 static void InitLibcFileIOFunctions() {
   g_libc_fopen = reinterpret_cast<FopenFunction>(
@@ -280,9 +283,9 @@
   if (!g_libc_fopen) {
     LOG(FATAL) << "Failed to get fopen() from libc.";
   } else if (!g_libc_fopen64) {
-#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
+#if !defined(OS_BSD)
     LOG(WARNING) << "Failed to get fopen64() from libc. Using fopen() instead.";
-#endif  // !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
+#endif  // !defined(OS_BSD)
     g_libc_fopen64 = g_libc_fopen;
   }
 
@@ -462,6 +465,11 @@
     CHECK(HANDLE_EINTR(send(sync_fds[1], "C", 1, MSG_NOSIGNAL)) == 1);
     (void) HANDLE_EINTR(close(sync_fds[1]));
 
+#if defined(OS_FREEBSD)
+    int exit_code = 
+      HANDLE_EINTR(waitpid(child_pid, NULL, WNOHANG)) == -1 ? 1 : 0;
+    _exit(exit_code);
+#else
     for (;;) {
       // Loop until we have reaped our one natural child
       siginfo_t reaped_child_info;
@@ -480,6 +488,7 @@
         _exit(exit_code);
       }
     }
+#endif
   } else {
     // The child needs to wait for the parent to close kZygoteIdFd to avoid a
     // race condition
@@ -573,7 +582,7 @@
       *has_started_new_init = true;
     }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
     // Previously, we required that the binary be non-readable. This causes the
     // kernel to mark the process as non-dumpable at startup. The thinking was
     // that, although we were putting the renderers into a PID namespace (with
