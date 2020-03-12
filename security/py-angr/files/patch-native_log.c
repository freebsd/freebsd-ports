--- native/log.c.orig	2019-04-16 21:08:57 UTC
+++ native/log.c
@@ -34,6 +34,9 @@
 #include <unistd.h>
 
 #include <sys/syscall.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
 
 static int log_fd = STDERR_FILENO;
 static bool log_fd_isatty = true;
@@ -107,7 +110,11 @@ void logLog(enum llevel_t ll, const char *fn, int ln, 
         dprintf(log_fd, "%s", logLevels[ll].prefix);
     }
     if (logLevels[ll].print_funcline) {
+#ifdef __FreeBSD__
+        dprintf(log_fd, "[%s][%s][%d] %s():%d ", timestr, logLevels[ll].descr, (pid_t)pthread_getthreadid_np, fn, ln);
+#else
         dprintf(log_fd, "[%s][%s][%d] %s():%d ", timestr, logLevels[ll].descr, (pid_t)syscall(__NR_gettid), fn, ln);
+#endif
     }
 
     va_list args;
