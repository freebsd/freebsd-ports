--- gen/compat.h.orig	2024-05-27 06:59:46 UTC
+++ gen/compat.h
@@ -48,6 +48,7 @@
 #define ETHERTYPE_FLOWCONTROL	0x8808
 #endif
 
+#if !defined(__FreeBSD__) || defined(__i386__)
 #ifndef atomic_fetchadd_32
 #define	atomic_fetchadd_32(t, v) __atomic_fetch_add(t, v, __ATOMIC_CONSUME)
 #endif
@@ -67,10 +68,11 @@ atomic_cmpset_32(volatile uint32_t *p, uint32_t cmpval
 	bool ret = __atomic_compare_exchange_n(p, &cmpval, newval, false, __ATOMIC_SEQ_CST, __ATOMIC_RELAXED);
 	return ret ? 1 : 0;
 }
-#endif
+#endif /* !defined(__FreeBSD__) || defined(__i386__) */
 
 #ifndef __unused
 #define __unused	__attribute__((unused))
+#endif
 #endif
 
 #endif /* _COMPAT_H_ */
