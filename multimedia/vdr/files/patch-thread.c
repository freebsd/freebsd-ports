--- thread.c.orig	2026-09-26 17:58:30 UTC
+++ thread.c
@@ -12,11 +12,15 @@
 #include <dlfcn.h>
 #include <errno.h>
 #include <execinfo.h>
-#include <linux/unistd.h>
-#include <malloc.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
+#include <signal.h>
 #include <stdarg.h>
 #include <stdlib.h>
+#ifdef __linux__
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/syscall.h>
 #include <sys/time.h>
@@ -165,7 +169,9 @@ cRwLock::cRwLock(bool PreferWriter)
   writeLockThreadId = 0;
   pthread_rwlockattr_t attr;
   pthread_rwlockattr_init(&attr);
+#ifdef __GLIBC__ // pthread_rwlockattr_setkind_np() is a GNU extension
   pthread_rwlockattr_setkind_np(&attr, PreferWriter ? PTHREAD_RWLOCK_PREFER_WRITER_NP : PTHREAD_RWLOCK_PREFER_READER_NP);
+#endif
   pthread_rwlock_init(&rwlock, &attr);
 }
 
@@ -216,7 +222,7 @@ cMutex::cMutex(void)
   locked = 0;
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
+  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
   pthread_mutex_init(&mutex, &attr);
 }
 
@@ -227,7 +233,7 @@ cMutex::~cMutex()
 
 bool cMutex::Lock(int TimeoutMs, bool *TimedOut)
 {
-  // PTHREAD_MUTEX_ERRORCHECK_NP rejects recursive entry from the same thread; handle the
+  // PTHREAD_MUTEX_ERRORCHECK rejects recursive entry from the same thread; handle the
   // nested cMutexLock case (documented in thread.h) here, like cRwLock does below:
   tThreadId ThisThreadId = cThread::ThreadId();
   if (lockThreadId == ThisThreadId && locked) {
@@ -286,8 +292,10 @@ void cThread::SetPriority(int Priority)
 
 void cThread::SetIOPriority(int Priority)
 {
+#ifdef __linux__ // I/O priorities are Linux specific
   if (syscall(SYS_ioprio_set, 1, 0, (Priority & 0xff) | (3 << 13)) < 0) // idle class
      LOG_ERROR;
+#endif
 }
 
 void cThread::SetDescription(const char *Description, ...)
@@ -405,7 +413,11 @@ tThreadId cThread::ThreadId(void)
   // fetches its own id on first use.
   static thread_local tThreadId threadId = 0;
   if (threadId == 0)
-     threadId = syscall(__NR_gettid);
+#ifdef __FreeBSD__
+     threadId = pthread_getthreadid_np();
+#else
+     threadId = syscall(SYS_gettid);
+#endif
   return threadId;
 }
 
