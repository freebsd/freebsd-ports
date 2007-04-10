--- src/pthread_debug.h.orig	Wed Feb 15 21:22:38 2006
+++ src/pthread_debug.h	Sat Apr  7 01:13:25 2007
@@ -15,8 +15,10 @@
 void Pthread_cond_wait(const char *caller, pthread_cond_t *cond, pthread_mutex_t *mutex);
 
 void print_pthread_attr(const char *caller, pthread_attr_t *attr);
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr);
 void print_pthread_condattr(const char *caller, pthread_condattr_t *c_attr);
+#endif
 
 
 #define  pthread_create(a, b, c, d)    Pthread_create(func, a, b, c, d)
