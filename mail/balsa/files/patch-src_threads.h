--- src/threads.h.orig	2009-08-30 05:03:26.000000000 -0400
+++ src/threads.h	2009-12-25 12:41:53.000000000 -0500
@@ -23,6 +23,7 @@
 #define __THREADS_H__
 
 #include <unistd.h>
+#include <pthread.h>
 
 /* FIXME: mailbox_lock is really an internal libbalsa mutex. */
 extern pthread_mutex_t mailbox_lock;
