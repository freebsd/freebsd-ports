--- freebsd/include/dahdi/compat/bsd.h.orig	2016-03-11 06:59:31.516533000 +0000
+++ freebsd/include/dahdi/compat/bsd.h	2016-03-11 07:05:34.327218000 +0000
@@ -45,6 +45,10 @@
 #include <machine/atomic.h>
 #include <machine/bus.h>
 
+#if __FreeBSD_version >= 1100101
+#define taskqueue_enqueue_fast(queue, task)	taskqueue_enqueue(queue, task)
+#endif
+
 #define D_VERSION_LINEAR	(((D_VERSION & 0xffff) << 16) | (((D_VERSION >> 16) & 0xff) << 8) | ((D_VERSION >> 24) & 0xff))
 
 #define LINUX_VERSION_CODE	KERNEL_VERSION(2, 6, 32)
@@ -66,9 +70,11 @@
 #define __be32  u_int32_t
 
 #if _BYTE_ORDER == _LITTLE_ENDIAN
+#define __LITTLE_ENDIAN
 #define __LITTLE_ENDIAN_BITFIELD
 #define __constant_htons(x)	((uint16_t) (((uint16_t) (x)) << 8 | ((uint16_t) (x)) >> 8))
 #elif _BYTE_ORDER == _BIG_ENDIAN
+#define __BIG_ENDIAN
 #define __BIG_ENDIAN_BITFIELD
 #define __constant_htons(x)	(x)
 #endif
@@ -454,7 +460,7 @@
 #define _module_ptr_args	__CONCAT(_module_ptr_args_, __LINE__)
 #define _module_ptr_init(field, val)					\
 	static struct module_ptr_args _module_ptr_args = {		\
-		(const void **) &(THIS_MODULE->field), val		\
+		(const void **) (uintptr_t) &(THIS_MODULE->field), val	\
 	};								\
 	SYSINIT(__CONCAT(_module_ptr_args, _init),			\
 		SI_SUB_KLD, SI_ORDER_FIRST,				\
