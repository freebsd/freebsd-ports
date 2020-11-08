--- libcdi/src/cdilib.c.orig	2020-02-22 18:32:17 UTC
+++ libcdi/src/cdilib.c
@@ -34056,11 +34056,13 @@ static pthread_mutex_t namespaceMutex;
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
@@ -34516,12 +34518,14 @@ static
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
