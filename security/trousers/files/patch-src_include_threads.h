--- src/include/threads.h.orig	2016-11-19 03:09:49 UTC
+++ src/include/threads.h
@@ -31,7 +31,7 @@
 #define COND_SIGNAL(c)		pthread_cond_signal(c)
 
 /* thread abstractions */
-#define THREAD_ID			((THREAD_TYPE)pthread_self())
+#define THREAD_ID			(long int)((THREAD_TYPE)pthread_self())
 #define THREAD_TYPE			pthread_t
 #define THREAD_JOIN			pthread_join
 #define THREAD_DETACH			pthread_detach
