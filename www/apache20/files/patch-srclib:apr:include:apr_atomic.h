--- srclib/apr/include/apr_atomic.h.orig	Sun Apr  7 22:54:09 2002
+++ srclib/apr/include/apr_atomic.h	Sun Apr  7 22:55:03 2002
@@ -191,10 +191,10 @@
 #include <machine/atomic.h>
 
 #define apr_atomic_t apr_uint32_t
-#define apr_atomic_add(mem, val)     atomic_add_int(mem,val)
-#define apr_atomic_dec(mem)          atomic_subtract_int(mem,1)
-#define apr_atomic_inc(mem)          atomic_add_int(mem,1)
-#define apr_atomic_set(mem, val)     atomic_set_int(mem, val)
+#define apr_atomic_add(mem, val)     (atomic_add_int(mem,val),mem)
+#define apr_atomic_dec(mem)          (atomic_subtract_int(mem,1),mem)
+#define apr_atomic_inc(mem)          (atomic_add_int(mem,1),mem)
+#define apr_atomic_set(mem, val)     (atomic_set_int(mem, val),mem)
 #define apr_atomic_read(mem)         *mem
 
 #define APR_ATOMIC_NEED_CAS_DEFAULT 1
