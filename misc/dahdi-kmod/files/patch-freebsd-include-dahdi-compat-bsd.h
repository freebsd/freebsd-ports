--- freebsd/include/dahdi/compat/bsd.h.orig	2015-03-22 00:41:01.923397000 +0600
+++ freebsd/include/dahdi/compat/bsd.h	2015-03-22 00:51:34.101470000 +0600
@@ -66,9 +66,11 @@
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
@@ -454,7 +456,7 @@
 #define _module_ptr_args	__CONCAT(_module_ptr_args_, __LINE__)
 #define _module_ptr_init(field, val)					\
 	static struct module_ptr_args _module_ptr_args = {		\
-		(const void **) &(THIS_MODULE->field), val		\
+		(const void **) (uintptr_t) &(THIS_MODULE->field), val	\
 	};								\
 	SYSINIT(__CONCAT(_module_ptr_args, _init),			\
 		SI_SUB_KLD, SI_ORDER_FIRST,				\
