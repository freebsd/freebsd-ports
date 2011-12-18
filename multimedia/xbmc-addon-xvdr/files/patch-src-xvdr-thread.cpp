--- a/src/xvdr/thread.cpp
+++ b/src/xvdr/thread.cpp
@@ -29,10 +29,14 @@
 #include "thread.h"
 #include "client.h"
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
+
 #if !defined(__WINDOWS__)
 #include <sys/signal.h>
 #endif
@@ -163,7 +167,7 @@ cMutex::cMutex(void)
   locked = 0;
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
 #else
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
@@ -349,8 +353,8 @@ void cThread::Cancel(int WaitSeconds)
 
 tThreadId cThread::ThreadId(void)
 {
-#ifdef __APPLE__
-    return (int)pthread_self();
+#if defined(__APPLE__) || defined(__FreeBSD__)
+    return (tThreadId)pthread_self();
 #else
 #ifdef __WINDOWS__
   return GetCurrentThreadId();
