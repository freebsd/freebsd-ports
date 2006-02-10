--- lib/senna_in.h.orig	Fri Feb 10 12:01:06 2006
+++ lib/senna_in.h	Fri Feb 10 12:05:57 2006
@@ -83,6 +83,10 @@
 #define PATH_SEPARATOR "/"
 #endif /* WIN32 */
 
+#if defined(__FreeBSD__) && __FreeBSD__ <= 4
+typedef	u_int8_t	uint_least8_t;
+#endif
+
 #ifdef HAVE_PTHREAD_H
 #include <pthread.h>
 typedef pthread_mutex_t sen_mutex;
