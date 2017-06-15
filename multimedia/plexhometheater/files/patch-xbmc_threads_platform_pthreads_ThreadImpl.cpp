--- xbmc/threads/platform/pthreads/ThreadImpl.cpp.orig	2015-05-11 07:54:22 UTC
+++ xbmc/threads/platform/pthreads/ThreadImpl.cpp
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
 
@@ -59,11 +55,7 @@ void CThread::TermHandler() { }
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
