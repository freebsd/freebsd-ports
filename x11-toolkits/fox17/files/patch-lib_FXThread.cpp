--- lib/FXThread.cpp.orig	2011-05-19 09:10:16.000000000 +0200
+++ lib/FXThread.cpp	2011-05-19 09:10:38.000000000 +0200
@@ -599,7 +599,7 @@
   InitializeCriticalSection(((RWLOCK*)data)->mutex);
   InitializeCriticalSection(((RWLOCK*)data)->access);
   ((RWLOCK*)data)->readers=0;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
   // If this fails on your machine, determine what value
   // of sizeof(pthread_rwlock_t) is supposed to be on your
   // machine and mail it to: jeroen@fox-toolkit.com!!
