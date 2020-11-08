--- libcdi/src/resource_handle.c.orig	2020-04-22 13:06:24 UTC
+++ libcdi/src/resource_handle.c
@@ -208,12 +208,14 @@ static
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
