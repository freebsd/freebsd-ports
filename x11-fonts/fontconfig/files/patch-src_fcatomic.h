--- src/fcatomic.h.orig	2016-07-11 02:41:06 UTC
+++ src/fcatomic.h
@@ -96,7 +96,17 @@ typedef int fc_atomic_int_t;
 #define fc_atomic_int_add(AI, V)	__sync_fetch_and_add (&(AI), (V))
 
 #define fc_atomic_ptr_get(P)		(void *) (__sync_synchronize (), *(P))
+#if defined(__FreeBSD__) && defined(__mips_n64)
+#include <sys/types.h>
+#include <machine/atomic.h>
+#define fc_atomic_ptr_cmpexch(P,O,N)	atomic_cmpset_rel_64 ((uint64_t *)(P), (uint64_t)(O), (uint64_t)(N))
+#elif defined(__FreeBSD__) && defined(__mips)
+#include <sys/types.h>
+#include <machine/atomic.h>
+#define fc_atomic_ptr_cmpexch(P,O,N)	atomic_cmpset_rel_32 ((uint32_t *)(P), (uint32_t)(O), (uint32_t)(N))
+#else
 #define fc_atomic_ptr_cmpexch(P,O,N)	__sync_bool_compare_and_swap ((P), (O), (N))
+#endif /* defined(__FreeBSD__) && defined(__mips__) */
 
 
 #elif !defined(FC_NO_MT) && defined(HAVE_SOLARIS_ATOMIC_OPS)
