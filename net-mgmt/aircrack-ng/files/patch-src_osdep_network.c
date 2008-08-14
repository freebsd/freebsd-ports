--- src/osdep/network.c.orig	2008-06-10 02:55:09.000000000 +0700
+++ src/osdep/network.c	2008-08-11 13:29:42.000000000 +0700
@@ -32,6 +32,15 @@
 
 #ifdef __MACH__ 
 #include <libkern/OSByteOrder.h>
+#elif defined(__FreeBSD__)
+#include <machine/endian.h>
+#if BYTE_ORDER == BIG_ENDIAN
+# define __be32_to_cpu(x)	(x)
+# define __be64_to_cpu(x)	(x)
+#elif BYTE_ORDER == LITTLE_ENDIAN
+# define __be32_to_cpu(x)	__bswap32(x)
+# define __be64_to_cpu(x)	__bswap64(x)
+#endif
 #else
 #include <asm/byteorder.h>
 #endif /* __MACH__ */
