
$FreeBSD$

--- util/threads/VSemaphore.hxx	2003/01/19 14:09:49	1.1
+++ util/threads/VSemaphore.hxx	2003/01/19 14:10:16
@@ -59,6 +59,7 @@
 #endif
 
 #if defined( __linux__ ) || defined(__FreeBSD__) || defined (WIN32)
+#include <pthread.h>
 #include <semaphore.h>
 #else
 #include <synch.h>
