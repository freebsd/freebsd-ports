--- source/adios2/toolkit/profiling/taustubs/tautimer.cpp.orig	2019-07-28 09:15:02 UTC
+++ source/adios2/toolkit/profiling/taustubs/tautimer.cpp
@@ -21,6 +21,9 @@
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <thread>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <pthread_np.h>
+#endif
 
 /* Clean assertion handling */
 inline void _tautimer_assert(const char *expression, const char *file, int line)
@@ -204,6 +207,8 @@ TauTimer::TauTimer(void) : initialized(false)
 #if defined(__APPLE__) && defined(__MACH__)
     // why should Apple support gettid? BE DIFFERENT, BABY!
     pthread_threadid_np(NULL, &mytid);
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    mytid = pthread_getthreadid_np();
 #else
     mytid = (uint64_t)syscall(__NR_gettid);
 #endif
@@ -232,6 +237,8 @@ inline void TauTimer::_RegisterThread(void)
 #if defined(__APPLE__) && defined(__MACH__)
         // why should Apple support gettid? BE DIFFERENT, BABY!
         pthread_threadid_np(NULL, &mytid);
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+        mytid = pthread_getthreadid_np();
 #else
         mytid = (uint64_t)syscall(__NR_gettid);
 #endif
