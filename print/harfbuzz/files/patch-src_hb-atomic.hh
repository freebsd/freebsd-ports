--- src/hb-atomic.hh.orig	2018-09-10 09:05:27 UTC
+++ src/hb-atomic.hh
@@ -118,7 +118,12 @@ static_assert ((sizeof (LONG) == sizeof (int)), "");
 
 #define hb_atomic_int_impl_add(AI, V)		__sync_fetch_and_add ((AI), (V))
 
+#if defined(__FreeBSD__) && defined(__mips__)
+#include <machine/atomic.h>
+#define hb_atomic_ptr_impl_cmpexch(P,O,N)	atomic_cmpset_rel_32 ((uint32_t *)(P), (uint32_t)(O), (uint32_t)(N))
+#else
 #define hb_atomic_ptr_impl_cmpexch(P,O,N)	__sync_bool_compare_and_swap ((P), (O), (N))
+#endif
 
 
 #elif !defined(HB_NO_MT) && defined(HAVE_SOLARIS_ATOMIC_OPS)
