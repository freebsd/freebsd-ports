--- VdrReplacements.c.orig
+++ VdrReplacements.c
@@ -16,7 +16,7 @@
 cMutex::cMutex() {
         pthread_mutexattr_t attr;
         pthread_mutexattr_init(&attr);
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
         pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
 #else
         pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
