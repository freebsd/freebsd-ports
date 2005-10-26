--- src/os/unix/ngx_atomic.h.orig	Wed Oct 26 11:17:58 2005
+++ src/os/unix/ngx_atomic.h	Wed Oct 26 11:18:36 2005
@@ -154,7 +154,7 @@
 ngx_atomic_cmp_set(ngx_atomic_t *lock, ngx_atomic_uint_t old,
      ngx_atomic_uint_t set)
 {
-     if (*lock == old {
+     if (*lock == old) {
          *lock = set;
          return 1;
      }
@@ -174,8 +174,9 @@
      return old;
 }
 
-#endif
+#define ngx_memory_barrier()
 
+#endif
 
 void ngx_spinlock(ngx_atomic_t *lock, ngx_uint_t spin);
 
