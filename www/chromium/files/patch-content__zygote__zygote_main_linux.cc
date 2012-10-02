--- content/zygote/zygote_main_linux.cc.orig	2012-09-25 16:01:30.000000000 +0300
+++ content/zygote/zygote_main_linux.cc	2012-10-01 21:22:30.000000000 +0300
@@ -46,6 +46,9 @@
 #include <sys/signal.h>
 #else
 #include <signal.h>
+#if defined(OS_FREEBSD)
+#include <sys/wait.h>
+#endif
 #endif
 
 namespace content {
@@ -324,6 +327,11 @@
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
@@ -342,6 +350,7 @@
         _exit(exit_code);
       }
     }
+#endif
   } else {
     // The child needs to wait for the parent to close kZygoteIdFd to avoid a
     // race condition
@@ -395,7 +404,7 @@
       *has_started_new_init = true;
     }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
     // Previously, we required that the binary be non-readable. This causes the
     // kernel to mark the process as non-dumpable at startup. The thinking was
     // that, although we were putting the renderers into a PID namespace (with
@@ -448,8 +457,10 @@
                 ZygoteForkDelegate* forkdelegate) {
 #if !defined(CHROMIUM_SELINUX)
   g_am_zygote_or_renderer = true;
+#if !defined(OS_BSD)
   sandbox::InitLibcUrandomOverrides();
 #endif
+#endif
 
   LinuxSandbox* linux_sandbox = LinuxSandbox::GetInstance();
   // This will pre-initialize the various sandboxes that need it.
