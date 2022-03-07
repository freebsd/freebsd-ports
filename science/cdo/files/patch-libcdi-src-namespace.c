--- libcdi/src/namespace.c.orig	2022-01-21 08:38:53 UTC
+++ libcdi/src/namespace.c
@@ -88,11 +88,13 @@ static pthread_mutex_t namespaceMutex;
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
 
 #define NAMESPACE_LOCK() pthread_mutex_lock(&namespaceMutex)
