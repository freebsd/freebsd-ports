--- lib/FXThread.cpp.orig	2010-09-27 08:48:52.000000000 +0000
+++ lib/FXThread.cpp	2010-09-27 08:49:43.000000000 +0000
@@ -582,7 +582,7 @@
   InitializeCriticalSection(((RWLOCK*)data)->mutex);
   InitializeCriticalSection(((RWLOCK*)data)->access);
   ((RWLOCK*)data)->readers=0;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
   // If this fails on your machine, determine what value
   // of sizeof(pthread_rwlock_t) is supposed to be on your
   // machine and mail it to: jeroen@fox-toolkit.com!!
