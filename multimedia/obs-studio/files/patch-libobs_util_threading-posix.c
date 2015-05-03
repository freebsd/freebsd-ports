--- libobs/util/threading-posix.c.orig	2015-03-27 21:29:37 UTC
+++ libobs/util/threading-posix.c
@@ -26,6 +26,10 @@
 #include <semaphore.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
+
 #include "bmem.h"
 #include "threading.h"
 
@@ -256,6 +260,8 @@ void os_set_thread_name(const char *name
 {
 #if defined(__APPLE__)
 	pthread_setname_np(name);
+#elif defined(__FreeBSD__)
+	pthread_set_name_np(pthread_self(), name);
 #elif !defined(__MINGW32__)
 	pthread_setname_np(pthread_self(), name);
 #endif
