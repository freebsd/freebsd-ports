--- third_party/perfetto/src/base/unix_task_runner.cc.orig	2018-08-04 21:17:17.721052000 +0200
+++ third_party/perfetto/src/base/unix_task_runner.cc	2018-08-04 21:17:57.424940000 +0200
@@ -45,7 +45,7 @@
   control_read_.reset(pipe_fds[0]);
   control_write_.reset(pipe_fds[1]);
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   // We are never expecting to have more than a few bytes in the wake-up pipe.
   // Reduce the buffer size on Linux. Note that this gets rounded up to the page
   // size.
