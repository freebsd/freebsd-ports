--- slirpvde/ip.h	Sat Jan 29 15:02:08 2005
+++ slirpvde/ip.h	Sun Jan 30 14:00:32 2005
@@ -37,6 +37,31 @@
 #ifndef _IP_H_
 #define _IP_H_
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+
+#if !defined(__BYTE_ORDER)
+#if defined(_BYTE_ORDER)
+#define __BYTE_ORDER _BYTE_ORDER
+#elif defined(BYTE_ORDER)
+#define __BYTE_ORDER BYTE_ORDER
+#else
+#error BYTE_ORDER not defined
+#endif
+#endif /* !defined(__BYTE_ORDER) */
+
+#if !defined(__BIG_ENDIAN)
+#if defined(_BIG_ENDIAN)
+#define __BIG_ENDIAN _BIG_ENDIAN
+#elif defined(BIG_ENDIAN)
+#define __BIG_ENDIAN BIG_ENDIAN
+#else
+#error BIG_ENDIAN not defined
+#endif
+#endif /* !defined(__BIG_ENDIAN) */
+
+#endif /* __FreeBSD__ */
+
 #if __BYTE_ORDER == __BIG_ENDIAN
 # ifndef NTOHL
 #  define NTOHL(d)
