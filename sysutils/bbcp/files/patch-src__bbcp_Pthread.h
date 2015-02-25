--- src/bbcp_Pthread.h.orig	2015-01-16 13:41:31.000000000 -0800
+++ src/bbcp_Pthread.h	2015-01-16 13:42:14.000000000 -0800
@@ -108,7 +108,7 @@
 bbcp_Mutex *monMutex;
 };
 
-#if defined(MACOS) || defined(AIX)
+#if defined(MACOS) || defined(AIX) || defined(FREEBSD)
 class bbcp_Semaphore
 {
 public:
