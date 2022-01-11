--- libcdi/src/cdilib.c.orig	2021-06-05 06:43:11 UTC
+++ libcdi/src/cdilib.c
@@ -33941,11 +33941,13 @@ static pthread_mutex_t namespaceMutex;
 static void
 namespaceInitialize(void)
 {
+#if defined(PTHREAD_MUTEXATTR)
   pthread_mutexattr_t ma;
   pthread_mutexattr_init(&ma);
   pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_RECURSIVE);
   pthread_mutex_init(&namespaceMutex, &ma);
   pthread_mutexattr_destroy(&ma);
+#endif
 }
 
 #  define NAMESPACE_LOCK()         pthread_mutex_lock(&namespaceMutex)
@@ -34401,12 +34403,14 @@ static
 void listInitialize ( void )
 {
 #if  defined  (HAVE_LIBPTHREAD)
+#if defined(PTHREAD_MUTEXATTR)
   pthread_mutexattr_t ma;
   pthread_mutexattr_init(&ma);
   pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_RECURSIVE);
   /* initialize global API mutex lock */
   pthread_mutex_init ( &listMutex, &ma);
   pthread_mutexattr_destroy(&ma);
+#endif
 #endif
   /* file is special and has its own table, which needs to be
    * created, before we register the listDestroy exit handler */
