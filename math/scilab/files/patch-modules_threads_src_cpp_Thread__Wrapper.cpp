--- modules/threads/src/cpp/Thread_Wrapper.cpp.orig	2020-02-25 10:00:14 UTC
+++ modules/threads/src/cpp/Thread_Wrapper.cpp
@@ -52,13 +52,6 @@ void __InitSignalLock(__threadSignalLock *lockName)
 #ifdef _MSC_VER
     InitializeCriticalSection(lockName);
 #else
-    /* PTHREAD_MUTEX_ERRORCHECK needed for a safe release atexit when we try to release without knowing if we own the lock
-       PTHREAD_PROCESS_SHARED needed for interprocess synch (plus alloc in shared mem thread_mutexattr_settype
-       Linux uses PTHREAD_MUTEX_ERRORCHECK_NP other Posix use PTHREAD_MUTEX_ERRORCHECK
-    */
-#ifndef PTHREAD_MUTEX_ERRORCHECK
-#define PTHREAD_MUTEX_ERRORCHECK PTHREAD_MUTEX_ERRORCHECK_NP
-#endif
     pthread_mutexattr_t attr;
     pthread_mutexattr_init (&attr);
     pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
