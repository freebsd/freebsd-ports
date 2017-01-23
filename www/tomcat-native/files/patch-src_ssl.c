--- src/ssl.c.orig	2017-01-23 08:26:47 UTC
+++ src/ssl.c
@@ -428,6 +428,8 @@ static unsigned long ssl_thread_id(void)
     uint64_t tid;
     pthread_threadid_np(NULL, &tid);
     return (unsigned long)tid;
+#elif defined(__FreeBSD__)
+    return (unsigned long)pthread_threadid_np();
 #elif defined(__linux__)
     return (unsigned long)syscall(SYS_gettid);
 #else
