--- src/pthread_debug.h.orig	Wed Feb 15 21:22:38 2006
+++ src/pthread_debug.h	Mon Dec 18 10:01:00 2006
@@ -15,8 +15,10 @@
 void Pthread_cond_wait(const char *caller, pthread_cond_t *cond, pthread_mutex_t *mutex);
 
 void print_pthread_attr(const char *caller, pthread_attr_t *attr);
+#if __FreeBSD_version >= 600000
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr);
 void print_pthread_condattr(const char *caller, pthread_condattr_t *c_attr);
+#endif
 
 
 #define  pthread_create(a, b, c, d)    Pthread_create(func, a, b, c, d)
