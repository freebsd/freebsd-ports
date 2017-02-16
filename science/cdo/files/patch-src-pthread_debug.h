--- src/pthread_debug.h.orig	2016-04-18 08:41:42 UTC
+++ src/pthread_debug.h
@@ -15,8 +15,10 @@ void Pthread_cond_signal(const char *cal
 void Pthread_cond_wait(const char *caller, pthread_cond_t *cond, pthread_mutex_t *mutex);
 
 void print_pthread_attr(const char *caller, pthread_attr_t *attr);
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr);
 void print_pthread_condattr(const char *caller, pthread_condattr_t *c_attr);
+#endif
 
 
 #define  pthread_create(a, b, c, d)    Pthread_create(__func__, a, b, c, d)
