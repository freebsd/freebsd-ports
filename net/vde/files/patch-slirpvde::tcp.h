--- slirpvde/tcp.h	Sat Jan 29 15:02:08 2005
+++ slirpvde/tcp.h	Sun Jan 30 14:00:50 2005
@@ -37,6 +37,31 @@
 #ifndef _TCP_H_
 #define _TCP_H_
 
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
 typedef	u_int32_t	tcp_seq;
 
 #define      PR_SLOWHZ       2               /* 2 slow timeouts per second (approx) */
