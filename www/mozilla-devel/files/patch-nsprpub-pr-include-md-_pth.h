--- nsprpub/pr/include/md/_pth.h.orig	Sun Jan 16 16:09:10 2005
+++ nsprpub/pr/include/md/_pth.h	Sun Jan 16 16:10:06 2005
@@ -84,7 +84,7 @@
 #define _PT_PTHREAD_MUTEXATTR_DESTROY(x)  /* */
 #define _PT_PTHREAD_MUTEX_INIT(m, a)      (memset(&(m), 0, sizeof(m)), \
                                       pthread_mutex_init(&(m), NULL))
-#define _PT_PTHREAD_MUTEX_IS_LOCKED(m)    (EBUSY == pthread_mutex_trylock(&(m)))
+#define _PT_PTHREAD_MUTEX_IS_LOCKED(m)    (0 != pthread_mutex_trylock(&(m)))
 #define _PT_PTHREAD_CONDATTR_INIT(x)      0
 #define _PT_PTHREAD_CONDATTR_DESTROY(x)   /* */
 #define _PT_PTHREAD_COND_INIT(m, a)       (memset(&(m), 0, sizeof(m)), \
