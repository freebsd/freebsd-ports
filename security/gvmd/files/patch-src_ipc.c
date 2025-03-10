--- src/ipc.c	2024-09-11 02:00:14.000000000 -0700
+++ src/ipc.c	2024-09-19 23:21:42.837138000 -0700
@@ -30,6 +30,9 @@
 
 #include <errno.h>
 #include <sys/sem.h>
+#if defined(__FreeBSD__)
+#include <sys/time.h>
+#endif
 
 #include "ipc.h"
 #include "manage.h"
@@ -60,7 +63,134 @@
   struct seminfo *__buf;  ///< Buffer for IPC_INFO (Linux-specific)
 };
 
+#if defined(__FreeBSD__)
 /**
+ * FreeBSD not support semtimedop function. I have added here an old implementation
+ * shared at FreeBSD mail list by Michael B Allen <ioplex at gmail.com>:
+ * https://lists.freebsd.org/pipermail/freebsd-hackers/2008-July/025483.html
+ */
+void
+_timeval_diff(struct timeval * tv1, struct timeval * tv2, struct timeval * tvd) {
+  tvd -> tv_sec = tv1 -> tv_sec - tv2 -> tv_sec;
+  tvd -> tv_usec = tv1 -> tv_usec - tv2 -> tv_usec;
+  if (tvd -> tv_usec < 0) {
+    tvd -> tv_usec = 1000000 - tvd -> tv_usec;
+    tvd -> tv_sec--;
+  }
+}
+
+void
+signal_ignore(int s, siginfo_t * si, void * ctx) {}
+
+int
+_semtimedop(int semid, struct sembuf * array, size_t nops, struct timespec * _timeout) {
+  struct timeval timeout, before, after;
+  struct itimerval value, ovalue;
+  struct sigaction sa, osa;
+  int ret;
+
+  if (_timeout) {
+    timeout.tv_sec = _timeout -> tv_sec;
+    timeout.tv_usec = _timeout -> tv_nsec / 1000;
+
+    if (gettimeofday( & before, NULL) == -1) {
+      errno = EFAULT;
+      return -1;
+    }
+
+    if (timeout.tv_sec == 0 && timeout.tv_usec < 5000) {
+      struct timeval tsleep, tend;
+      struct sembuf wait;
+
+      wait = * array;
+      wait.sem_flg |= IPC_NOWAIT;
+
+      tsleep.tv_sec = 0;
+      tsleep.tv_usec = 1;
+
+      timeradd( & before, & timeout, & tend);
+
+      for (;;) {
+        struct timeval tnow, tleft;
+        struct timespec ts;
+
+        ret = semop(semid, & wait, nops);
+
+        if (ret == 0) {
+          return 0;
+        } else if (errno != EAGAIN) {
+          break;
+        }
+
+        if (gettimeofday( & tnow, NULL) == -1) {
+          errno = EFAULT;
+          break;
+        }
+
+        if (timercmp( & tnow, & tend, >= )) {
+          errno = EAGAIN;
+          break;
+        }
+
+        timersub( & tend, & tnow, & tleft);
+
+        if (tsleep.tv_usec > tleft.tv_usec)
+          tsleep.tv_usec = tleft.tv_usec;
+
+        ts.tv_sec = 0;
+        ts.tv_nsec = tsleep.tv_usec * 1000;
+        nanosleep( & ts, NULL);
+
+        tsleep.tv_usec *= 10;
+      }
+
+      return -1;
+    }
+
+    memset( & value, 0, sizeof value);
+    value.it_value = timeout;
+
+    memset( & sa, 0, sizeof sa);
+    sa.sa_sigaction = signal_ignore;
+    sa.sa_flags = SA_SIGINFO;
+    sigemptyset( & sa.sa_mask);
+    sigaction(SIGALRM, & sa, & osa);
+
+    if (setitimer(ITIMER_REAL, & value, & ovalue) == -1) {
+      sigaction(SIGALRM, & osa, NULL);
+      return -1;
+    }
+  }
+
+  ret = semop(semid, array, nops);
+
+  if (_timeout) {
+    ret = setitimer(ITIMER_REAL, & ovalue, NULL);
+    if (ret < 0)
+      errno = EFAULT;
+
+    sigaction(SIGALRM, & osa, NULL);
+  }
+
+  if (ret == -1) {
+    if (_timeout) {
+      struct timeval elapsed;
+
+      if (gettimeofday( & after, NULL) == -1) {} else {
+        _timeval_diff( & after, & before, & elapsed);
+
+        if (timercmp( & elapsed, & timeout, >= ))
+          errno = EAGAIN;
+      }
+    }
+    return -1;
+  }
+
+  return 0;
+}
+#endif
+
+/**
  * @brief Initializes the semaphore set for gvmd actions.
  *
  * Needs max_concurrent_scan_updates to be set.
@@ -148,7 +278,11 @@
     tv_sec: timeout,
   };
 
+#if defined(__FreeBSD__)
+  ret = _semtimedop (semaphore_set, &op, 1, timeout > 0 ? &ts : NULL);
+#else
   ret = semtimedop (semaphore_set, &op, 1, timeout > 0 ? &ts : NULL);
+#endif
   if (ret)
     {
       if (errno == EAGAIN)
