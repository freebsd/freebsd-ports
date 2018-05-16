--- src/pthread_debug.h.orig	2018-05-09 08:49:58 UTC
+++ src/pthread_debug.h
@@ -26,20 +26,22 @@ int Pthread_create(const char *caller, p
 
 int Pthread_join(const char *caller, pthread_t th, void **thread_return);
 
-void Pthread_mutex_lock(const char *caller, pthread_mutex_t *mutex);
-void Pthread_mutex_lock(const char *caller, std::mutex &p_mutex);
+int Pthread_mutex_lock(const char *caller, pthread_mutex_t *mutex);
+int Pthread_mutex_lock(const char *caller, std::mutex &p_mutex);
 
-void Pthread_mutex_unlock(const char *caller, pthread_mutex_t *mutex);
-void Pthread_mutex_unlock(const char *caller, std::mutex &p_mutex);
+int Pthread_mutex_unlock(const char *caller, pthread_mutex_t *mutex);
+int Pthread_mutex_unlock(const char *caller, std::mutex &p_mutex);
 
-void Pthread_cond_signal(const char *caller, pthread_cond_t *cond);
-void Pthread_cond_signal(const char *caller, std::condition_variable &p_cond_var);
-void Pthread_cond_wait(const char *caller, pthread_cond_t *cond, pthread_mutex_t *mutex);
-void Pthread_cond_wait(const char *caller, std::condition_variable &p_cond_var, std::unique_lock<std::mutex> &p_mutex);
+int Pthread_cond_signal(const char *caller, pthread_cond_t *cond);
+int Pthread_cond_signal(const char *caller, std::condition_variable &p_cond_var);
+int Pthread_cond_wait(const char *caller, pthread_cond_t *cond, pthread_mutex_t *mutex);
+int Pthread_cond_wait(const char *caller, std::condition_variable &p_cond_var, std::unique_lock<std::mutex> &p_mutex);
 
 void print_pthread_attr(const char *caller, pthread_attr_t *attr);
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller, pthread_mutexattr_t *m_attr);
 void print_pthread_condattr(const char *caller, pthread_condattr_t *c_attr);
+#endif
 
 #define pthread_create(a, b, c, d) Pthread_create(__func__, a, b, c, d)
 #define pthread_join(a, b) Pthread_join(__func__, a, b)
