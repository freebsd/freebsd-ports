--- net/instaweb/util/pthread_rw_lock.cc.orig	2011-10-31 15:25:58.000000000 +0000
+++ net/instaweb/util/pthread_rw_lock.cc	2011-10-31 15:30:18.000000000 +0000
@@ -27,8 +27,10 @@
   // New writer lock call is given preference over existing reader lock calls,
   // so that writer lock call will never get starved. However, it is not allowed
   // if there exists any recursive reader lock call to prevent deadlocks.
+#ifdef PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP
   pthread_rwlockattr_setkind_np(&attr_,
                                 PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
+#endif
   pthread_rwlock_init(&rwlock_, &attr_);
 }
 
