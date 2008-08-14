--- src/airserv-ng.c.orig	2008-06-10 02:55:09.000000000 +0700
+++ src/airserv-ng.c	2008-08-11 13:39:46.000000000 +0700
@@ -37,6 +37,15 @@
 
 #ifdef __MACH__
 #include <libkern/OSByteOrder.h>
+#elif defined(__FreeBSD__)
+#include <machine/endian.h>
+#if BYTE_ORDER == BIG_ENDIAN
+# define __cpu_to_be32(x)	(x)
+# define __cpu_to_be64(x)	(x)
+#elif BYTE_ORDER == LITTLE_ENDIAN
+# define __cpu_to_be32(x)	__bswap32(x)
+# define __cpu_to_be64(x)	__bswap64(x)
+#endif
 #else
 #include <asm/byteorder.h>
 #endif /* __MACH__ */
