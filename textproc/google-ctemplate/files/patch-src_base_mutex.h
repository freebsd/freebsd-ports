--- src/base/mutex.h.orig	Wed Jun 13 22:51:52 2007
+++ src/base/mutex.h	Wed Jun 13 22:49:02 2007
@@ -52,7 +52,7 @@
 #elif defined(HAVE_PTHREAD) && defined(HAVE_RWLOCK)
   // Needed for pthread_rwlock_*.  If it causes problems, you could take
   // it out, but then you'd have to unset HAVE_RWLOCK (at least on linux).
-# define _XOPEN_SOURCE 500   // needed to get the rwlock calls
+//# define _XOPEN_SOURCE 500   // needed to get the rwlock calls
 # include <pthread.h>
   typedef pthread_rwlock_t MutexType;
 #elif defined(HAVE_PTHREAD)
