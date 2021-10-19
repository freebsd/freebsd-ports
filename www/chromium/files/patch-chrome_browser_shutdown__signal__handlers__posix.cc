--- chrome/browser/shutdown_signal_handlers_posix.cc.orig	2021-10-07 15:08:14 UTC
+++ chrome/browser/shutdown_signal_handlers_posix.cc
@@ -186,7 +186,11 @@ void InstallShutdownSignalHandlers(
   g_pipe_pid = getpid();
   g_shutdown_pipe_read_fd = pipefd[0];
   g_shutdown_pipe_write_fd = pipefd[1];
-#if !defined(ADDRESS_SANITIZER)
+#if defined(OS_BSD)
+  // PTHREAD_STACK_MIN causes Chromium to crash under FreeBSD,
+  // we request the default pthread stack size by specifying 0 here.
+  const size_t kShutdownDetectorThreadStackSize = 0;
+#elif !defined(ADDRESS_SANITIZER)
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 2;
 #else
   // ASan instrumentation bloats the stack frames, so we need to increase the
