--- src/bbcp_Pthread.C.orig	2015-01-16 13:38:06.000000000 -0800
+++ src/bbcp_Pthread.C	2015-01-16 13:39:48.000000000 -0800
@@ -128,7 +128,7 @@
 /*                              C o n d W a i t                               */
 /******************************************************************************/
 
-#if defined(MACOS) || defined(AIX)
+#if defined(MACOS) || defined(AIX) || defined(FREEBSD)
 
 int bbcp_Semaphore::CondWait()
 {
@@ -215,7 +215,7 @@
 void *bbcp_Thread_Wait(pthread_t tid)
     {long retc;
      void *tstat;
-     if (retc = pthread_join(tid, (void **)&tstat)) tstat = (void *)retc;
+     if ((retc = pthread_join(tid, (void **)&tstat))) tstat = (void *)retc;
      return tstat;
     }
 
