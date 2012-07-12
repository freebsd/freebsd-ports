--- chrome/browser/chrome_browser_main_posix.cc.orig	2012-05-30 10:01:59.000000000 +0300
+++ chrome/browser/chrome_browser_main_posix.cc	2012-06-05 21:35:31.000000000 +0300
@@ -238,7 +238,13 @@
     g_shutdown_pipe_read_fd = pipefd[0];
     g_shutdown_pipe_write_fd = pipefd[1];
 #if !defined(ADDRESS_SANITIZER)
+#if defined(OS_FREEBSD)
+    // PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+    // we request the default pthread stack size by specifying 0 here.
+    const size_t kShutdownDetectorThreadStackSize = 0;
+#else
     const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN;
+#endif
 #else
     // ASan instrumentation bloats the stack, so we need to increase the stack
     // size to avoid hitting the guard page.
