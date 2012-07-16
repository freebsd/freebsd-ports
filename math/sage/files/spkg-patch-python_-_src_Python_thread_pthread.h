--- python-2.7.3.p0/src/Python/thread_pthread.h.orig	2011-06-11 15:46:28.000000000 +0000
+++ python-2.7.3.p0/src/Python/thread_pthread.h	2012-04-22 00:23:46.000000000 +0000
@@ -38,13 +38,18 @@
 #endif
 #endif
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
+
 /* The POSIX spec says that implementations supporting the sem_*
    family of functions must indicate this by defining
    _POSIX_SEMAPHORES. */
 #ifdef _POSIX_SEMAPHORES
 /* On FreeBSD 4.x, _POSIX_SEMAPHORES is defined empty, so
    we need to add 0 to make it work there as well. */
-#if (_POSIX_SEMAPHORES+0) == -1
+#if defined(__FreeBSD__) && __FreeBSD_version < 701104 && \
+    (_POSIX_SEMAPHORES+0) == -1
 #define HAVE_BROKEN_POSIX_SEMAPHORES
 #else
 #include <semaphore.h>
@@ -56,7 +61,6 @@
    in default setting.  So the process scope is preferred to get
    enough number of threads to work. */
 #ifdef __FreeBSD__
-#include <osreldate.h>
 #if __FreeBSD_version >= 500000 && __FreeBSD_version < 504101
 #undef PTHREAD_SYSTEM_SCHED_SUPPORTED
 #endif
@@ -161,6 +165,7 @@
 {
     pthread_t th;
     int status;
+    sigset_t set, oset;
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
     pthread_attr_t attrs;
 #endif
@@ -189,6 +194,8 @@
 #if defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
     pthread_attr_setscope(&attrs, PTHREAD_SCOPE_SYSTEM);
 #endif
+    sigfillset(&set);
+    SET_THREAD_SIGMASK(SIG_BLOCK, &set, &oset);
 
     status = pthread_create(&th,
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
@@ -200,6 +207,7 @@
                              (void *)arg
                              );
 
+    SET_THREAD_SIGMASK(SIG_SETMASK, &oset, NULL);
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
     pthread_attr_destroy(&attrs);
 #endif
