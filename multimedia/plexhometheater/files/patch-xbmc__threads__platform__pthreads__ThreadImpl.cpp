--- xbmc/threads/platform/pthreads/ThreadImpl.cpp.orig	2013-05-13 11:32:04.000000000 +0200
+++ xbmc/threads/platform/pthreads/ThreadImpl.cpp	2013-05-13 11:47:27.000000000 +0200
@@ -29,12 +29,8 @@
 #include <string.h>
 #ifdef __FreeBSD__
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
 #ifdef __FreeBSD__
-#if __FreeBSD_version < 900031
-  long lwpid;
-  thr_self(&lwpid);
-  m_ThreadOpaque.LwpId = lwpid;
-#else
+#if __FreeBSD_version > 900030
   m_ThreadOpaque.LwpId = pthread_getthreadid_np();
 #endif
 #elif defined(TARGET_ANDROID)
