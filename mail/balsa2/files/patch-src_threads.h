--- src/threads.h.orig	Tue Dec 31 14:06:47 2002
+++ src/threads.h	Tue Dec 31 14:07:32 2002
@@ -21,6 +21,9 @@
 
 #ifndef __THREADS_H__
 #define __THREADS_H__
+
+#include <pthread.h>
+
 /* FIXME: mailbox_lock is really an internal libbalsa mutex. */
 extern pthread_mutex_t mailbox_lock;
 
