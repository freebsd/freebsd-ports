--- udf_bswap.h.orig	Wed Mar 23 18:00:36 2005
+++ udf_bswap.h		Wed Mar 23 19:00:10 2005
@@ -52,8 +52,10 @@
 /* rest only relevant for big endian machines */
 #if (BYTE_ORDER == BIG_ENDIAN)
 
+#if !defined(__FreeBSD__)
 #include <machine/bswap.h>
 #include <sys/bswap.h>
+#endif
 
 /* inlines for access to swapped data */
 static __inline u_int16_t udf_rw16 __P((u_int16_t));
