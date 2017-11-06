--- src/pthread_debug.h.orig	2017-06-16 08:43:18 UTC
+++ src/pthread_debug.h
@@ -8,15 +8,17 @@ int Pthread_create(const char *caller, p
 
 int Pthread_join(const char *caller, pthread_t th, void **thread_return);
 
-void Pthread_mutex_lock(const char *caller, pthread_mutex_t *mutex);
-void Pthread_mutex_unlock(const char *caller, pthread_mutex_t *mutex);
+int Pthread_mutex_lock(const char *caller, pthread_mutex_t *mutex);
+int Pthread_mutex_unlock(const char *caller, pthread_mutex_t *mutex);
 
-void Pthread_cond_signal(const char *caller, pthread_cond_t *cond);
-void Pthread_cond_wait(const char *caller, pthread_cond_t *cond, pthread_mutex_t *mutex);
+int Pthread_cond_signal(const char *caller, pthread_cond_t *cond);
+int Pthread_cond_wait(const char *caller, pthread_cond_t *cond, pthread_mutex_t *mutex);
 
 void print_pthread_attr(const char *caller, pthread_attr_t *attr);
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr);
 void print_pthread_condattr(const char *caller, pthread_condattr_t *c_attr);
+#endif
 
 
 #define  pthread_create(a, b, c, d)    Pthread_create(__func__, a, b, c, d)
