--- src/environment.h.orig	Wed Dec 13 17:33:19 2000
+++ src/environment.h	Wed Dec 13 17:33:40 2000
@@ -55,7 +55,7 @@
 #include	<thread.h>
 #endif
 #include	<pthread.h>
-#if	!defined(HAVE_PTHREAD_RWLOCK_INIT)
+#if	!defined(HAVE_PTHREAD_RWLOCK_INIT) && !defined(FREEBSD)
 #include	"rwlock.h"
 #endif
