--- chrome/browser/chrome_browser_main_posix.cc.orig	2012-05-26 01:03:17.150187321 +0300
+++ chrome/browser/chrome_browser_main_posix.cc	2012-05-26 01:49:33.217175094 +0300
@@ -237,7 +237,13 @@
   } else {
     g_shutdown_pipe_read_fd = pipefd[0];
     g_shutdown_pipe_write_fd = pipefd[1];
+#if defined(OS_FREEBSD)
+    // gliaskos: PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+    // we request the default pthread stack size by specifying 0 here.
+    const size_t kShutdownDetectorThreadStackSize = 0;
+#else
     const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN;
+#endif
     // TODO(viettrungluu,willchan): crbug.com/29675 - This currently leaks, so
     // if you change this, you'll probably need to change the suppression.
     if (!base::PlatformThread::CreateNonJoinable(
