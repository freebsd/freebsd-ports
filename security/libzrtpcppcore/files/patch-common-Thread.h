--- common/Thread.h.orig	2014-11-18 15:26:49 UTC
+++ common/Thread.h
@@ -62,7 +62,7 @@ typedef void *LPVOID;
 
 #if defined(AS400) || defined(OS400)
 typedef pthread_id_np_t ThreadId_t;
-#elif defined(VMS) || defined(__NetBSD__)
+#elif defined(VMS) || defined(__NetBSD__) || defined(__FreeBSD__)
 typedef pthread_t ThreadId_t;
 #else
 #ifdef USE_BEGIN_THREAD
