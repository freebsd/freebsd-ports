--- xbmc/threads/platform/pthreads/ThreadImpl.cpp.orig	2013-12-03 16:25:00.000000000 +0100
+++ xbmc/threads/platform/pthreads/ThreadImpl.cpp	2013-12-03 16:26:01.000000000 +0100
@@ -29,12 +29,8 @@
 #include <string.h>
 #ifdef TARGET_FREEBSD
 #include <sys/param.h>
-#if __FreeBSD_version < 900031
-#include <sys/thr.h>
-#else
 #include <pthread_np.h>
 #endif
-#endif
 
 #include <signal.h>
 
@@ -59,11 +55,7 @@
 void CThread::SetThreadInfo()
 {
 #ifdef TARGET_FREEBSD
-#if __FreeBSD_version < 900031
-  long lwpid;
-  thr_self(&lwpid);
-  m_ThreadOpaque.LwpId = lwpid;
-#else
+#if __FreeBSD_version > 900030
   m_ThreadOpaque.LwpId = pthread_getthreadid_np();
 #endif
 #elif defined(TARGET_ANDROID)
