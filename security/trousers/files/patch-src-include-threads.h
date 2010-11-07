--- src/include/threads.h.orig	2010-05-03 11:54:15.000000000 +0900
+++ src/include/threads.h	2010-10-24 21:04:04.828558009 +0900
@@ -31,7 +31,7 @@
 #define COND_SIGNAL(c)		pthread_cond_signal(c)
 
 /* thread abstractions */
-#define THREAD_ID			((THREAD_TYPE)pthread_self())
+#define THREAD_ID			(long int)((THREAD_TYPE)pthread_self())
 #define THREAD_TYPE			pthread_t
 #define THREAD_JOIN			pthread_join
 #define THREAD_DETACH			pthread_detach
