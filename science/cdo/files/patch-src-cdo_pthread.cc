--- src/cdo_pthread.cc.orig	2017-07-03 08:59:29 UTC
+++ src/cdo_pthread.cc
@@ -32,8 +32,10 @@ void print_pthread_info()
 {
 #if defined(HAVE_LIBPTHREAD)
   pthread_attr_t attr;
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
   pthread_mutexattr_t m_attr;
   pthread_condattr_t c_attr;
+#endif
 
 #if defined(PTHREAD_KEYS_MAX)
   fprintf(stderr, "PTHREAD_KEYS_MAX    = %d\n", PTHREAD_KEYS_MAX);
@@ -54,6 +56,7 @@ void print_pthread_info()
   print_pthread_attr("Default pthread attr", &attr);
   pthread_attr_destroy(&attr);
 
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
   pthread_mutexattr_init(&m_attr);
   print_pthread_mutexattr("Default pthread mutexattr", &m_attr);
   pthread_mutexattr_destroy(&m_attr);
@@ -61,6 +64,7 @@ void print_pthread_info()
   pthread_condattr_init(&c_attr);
   print_pthread_condattr("Default pthread condattr ", &c_attr);
   pthread_condattr_destroy(&c_attr);
+#endif
 
   fprintf(stderr, "\n");
 #endif
