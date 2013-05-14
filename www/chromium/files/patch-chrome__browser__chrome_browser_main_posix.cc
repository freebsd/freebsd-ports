--- chrome/browser/chrome_browser_main_posix.cc.orig	2013-02-28 10:15:23.000000000 +0200
+++ chrome/browser/chrome_browser_main_posix.cc	2013-03-06 20:31:24.000000000 +0200
@@ -310,6 +310,11 @@
     g_pipe_pid = getpid();
     g_shutdown_pipe_read_fd = pipefd[0];
     g_shutdown_pipe_write_fd = pipefd[1];
+#if defined(OS_FREEBSD)
+    // PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+    // we request the default pthread stack size by specifying 0 here.
+    const size_t kShutdownDetectorThreadStackSize = 0;
+#else
 #if !defined(ADDRESS_SANITIZER) && !defined(KEEP_SHADOW_STACKS)
     const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN;
 #else
@@ -318,6 +323,7 @@
     // size to avoid hitting the guard page.
     const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 4;
 #endif
+#endif // OS_FREEBSD
     // TODO(viettrungluu,willchan): crbug.com/29675 - This currently leaks, so
     // if you change this, you'll probably need to change the suppression.
     if (!base::PlatformThread::CreateNonJoinable(
