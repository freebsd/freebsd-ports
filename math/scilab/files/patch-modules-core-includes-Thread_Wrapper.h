--- modules/core/includes/Thread_Wrapper.h.orig	2010-09-01 02:34:21.000000000 -0700
+++ modules/core/includes/Thread_Wrapper.h	2010-09-01 02:34:47.000000000 -0700
@@ -70,13 +70,6 @@
 #define __Lock(lockName)			pthread_mutex_lock(lockName)
 
 #define __UnLock(lockName)			pthread_mutex_unlock(lockName)
-/* PTHREAD_MUTEX_ERRORCHECK needed for a safe release atexit when we try to release without knowing if we own the lock
-PTHREAD_PROCESS_SHARED needed for interprocess synch (plus alloc in shared mem thread_mutexattr_settype
-Linux uses PTHREAD_MUTEX_ERRORCHECK_NP other Posix use PTHREAD_MUTEX_ERRORCHECK
-*/
-#ifndef PTHREAD_MUTEX_ERRORCHECK
-#define PTHREAD_MUTEX_ERRORCHECK PTHREAD_MUTEX_ERRORCHECK_NP
-#endif
 #define __InitSignalLock(lockName) \
     do { \
     pthread_mutexattr_t attr; \
