--- src/missing/ipv6_missing.h.orig	Tue Dec  3 06:05:18 2002
+++ src/missing/ipv6_missing.h	Sat Sep  4 16:05:28 2004
@@ -1,20 +1,32 @@
 #ifndef __IPV6_MISSING_H
 #define __IPV6_MISSING_H
 
+/* Correspond some of these values with present-day FreeBSD;
+ * verified on 4.10-STABLE and 5.3-BETA2.
+ */
+
+#ifndef EAI_MEMORY
+#	define EAI_MEMORY	6
+#endif
 #ifndef EAI_NODATA
-#	define EAI_NODATA	1
-#	define EAI_MEMORY	2
+#	define EAI_NODATA	7
 #endif
 
 #ifndef AI_PASSIVE
-#	define AI_PASSIVE		1
-#	define AI_CANONNAME		2
+#	define AI_PASSIVE	0x00000001
+#endif
+#ifndef AI_CANONNAME
+#	define AI_CANONNAME	0x00000002
 #endif
 
 #ifndef NI_NUMERICHOST
-#	define NI_NUMERICHOST	2
-#	define NI_NAMEREQD		4
-#	define NI_NUMERICSERV	8
+#	define NI_NUMERICHOST	0x00000002
+#endif
+#ifndef NI_NAMEREQD
+#	define NI_NAMEREQD	0x00000004
+#endif
+#ifndef NI_NUMERICSERV
+#	define NI_NUMERICSERV	0x00000008
 #endif
 
 #ifndef HAVE_STRUCT_ADDRINFO
