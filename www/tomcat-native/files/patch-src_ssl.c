--- src/ssl.c.orig	2019-06-26 11:12:00 UTC
+++ src/ssl.c
@@ -24,6 +24,10 @@
 #include <sys/syscall.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
+
 #ifdef HAVE_OPENSSL
 #include "ssl_private.h"
 
@@ -472,6 +476,8 @@ static unsigned long ssl_thread_id(void)
     uint64_t tid;
     pthread_threadid_np(NULL, &tid);
     return (unsigned long)tid;
+#elif defined(__FreeBSD__)
+    return (unsigned long)pthread_getthreadid_np();
 #elif defined(__linux__)
     return (unsigned long)syscall(SYS_gettid);
 #else
