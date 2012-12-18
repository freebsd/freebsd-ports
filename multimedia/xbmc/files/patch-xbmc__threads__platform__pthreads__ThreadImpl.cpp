--- xbmc/threads/platform/pthreads/ThreadImpl.cpp.orig	2012-09-21 15:52:13.000000000 +0200
+++ xbmc/threads/platform/pthreads/ThreadImpl.cpp	2012-09-21 15:55:45.000000000 +0200
@@ -59,12 +59,12 @@
 void CThread::SetThreadInfo()
 {
 #ifdef __FreeBSD__
-#if __FreeBSD_version < 900031
+#if __FreeBSD_version > 900030
+  m_ThreadOpaque.LwpId = pthread_getthreadid_np();
+#elif __FreeBSD_version > 800000
   long lwpid;
   thr_self(&lwpid);
   m_ThreadOpaque.LwpId = lwpid;
-#else
-  m_ThreadOpaque.LwpId = pthread_getthreadid_np();
 #endif
 #elif defined(TARGET_ANDROID)
   m_ThreadOpaque.LwpId = gettid();
