--- chrome/app/shutdown_signal_handlers_posix.cc.orig	2018-12-03 21:16:37.000000000 +0100
+++ chrome/app/shutdown_signal_handlers_posix.cc	2018-12-05 14:20:17.094777000 +0100
@@ -183,7 +183,11 @@
   g_pipe_pid = getpid();
   g_shutdown_pipe_read_fd = pipefd[0];
   g_shutdown_pipe_write_fd = pipefd[1];
-#if !defined(ADDRESS_SANITIZER)
+#if defined(OS_BSD)
+  // PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+  // we request the default pthread stack size by specifying 0 here.
+  const size_t kShutdownDetectorThreadStackSize = 0;
+#elif !defined(ADDRESS_SANITIZER)
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 2;
 #else
   // ASan instrumentation bloats the stack frames, so we need to increase the
