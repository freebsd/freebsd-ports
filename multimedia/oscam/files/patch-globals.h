--- globals.h.orig	2015-09-28 21:33:12 UTC
+++ globals.h
@@ -124,6 +124,18 @@ typedef unsigned char uchar;
 #define DEFAULT_AF AF_INET
 #endif
 
+#ifdef IPV6SUPPORT
+#if !defined s6_addr32 && defined __sun__
+#	define s6_addr32 _S6_un._S6_u32
+#elif !defined s6_addr32 && ( defined __OpenBSD__ || defined __FreeBSD__ ) 
+#	define s6_addr32 __u6_addr.__u6_addr32
+#endif	/* !defined s6_addr32 */
+#endif
+
+#ifndef SOL_TCP
+# define SOL_TCP IPPROTO_TCP
+#endif
+
 #ifndef NO_ENDIAN_H
 #if defined(__APPLE__)
 #include <machine/endian.h>
