--- xbmc/threads/platform/pthreads/ThreadImpl.cpp.orig	2013-03-07 15:55:46.000000000 +0100
+++ xbmc/threads/platform/pthreads/ThreadImpl.cpp	2013-03-07 15:55:58.000000000 +0100
@@ -58,11 +58,7 @@
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
