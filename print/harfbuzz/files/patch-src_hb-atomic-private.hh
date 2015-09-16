--- src/hb-atomic-private.hh.orig	2015-04-10 02:16:57 UTC
+++ src/hb-atomic-private.hh
@@ -103,8 +103,12 @@ typedef int hb_atomic_int_impl_t;
 #define hb_atomic_int_impl_add(AI, V)		__sync_fetch_and_add (&(AI), (V))
 
 #define hb_atomic_ptr_impl_get(P)		(void *) (__sync_synchronize (), *(P))
+#if defined(__FreeBSD__) && defined(__mips__)
+#include <machine/atomic.h>
+#define hb_atomic_ptr_impl_cmpexch(P,O,N)	atomic_cmpset_rel_32 ((uint32_t *)(P), (uint32_t)(O), (uint32_t)(N))
+#else
 #define hb_atomic_ptr_impl_cmpexch(P,O,N)	__sync_bool_compare_and_swap ((P), (O), (N))
-
+#endif
 
 #elif !defined(HB_NO_MT) && defined(HAVE_SOLARIS_ATOMIC_OPS)
 
