
--- apc_lock.h	2011/03/14 06:47:16	309203
+++ apc_lock.h	2011/05/22 17:18:49	311339
@@ -154,7 +154,7 @@
 # define apc_lck_nb_lock(a)    apc_fcntl_nonblocking_lock(a TSRMLS_CC)
 # define apc_lck_rdlock(a)     apc_fcntl_rdlock(a TSRMLS_CC)
 # define apc_lck_unlock(a)     apc_fcntl_unlock(a TSRMLS_CC)
-# define apc_lck_rdunlock(a)   apc_fcntl_unlock(&a TSRMLS_CC)
+# define apc_lck_rdunlock(a)   apc_fcntl_unlock(a TSRMLS_CC)
 #endif
 
 #endif


