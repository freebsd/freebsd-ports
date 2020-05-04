--- src/util.h.orig	2019-01-05 13:22:11 UTC
+++ src/util.h
@@ -102,9 +102,9 @@ extern struct timeval _mysleep;
 #ifdef LIBVNCSERVER_HAVE_LIBPTHREAD
 extern MUTEX(x11Mutex);
 extern MUTEX(scrollMutex);
-MUTEX(clientMutex);
-MUTEX(inputMutex);
-MUTEX(pointerMutex);
+extern MUTEX(clientMutex);
+extern MUTEX(inputMutex);
+extern MUTEX(pointerMutex);
 #endif
 
 #define X_INIT INIT_MUTEX(x11Mutex)
