--- src/pmacct.h.orig	2026-09-16 06:48:00 UTC
+++ src/pmacct.h
@@ -106,9 +106,13 @@
 #endif
 
 #if defined IM_BIG_ENDIAN
+#undef ntohs
 #define ntohs(x) (x)
+#undef ntohl
 #define ntohl(x) (x)
+#undef htons
 #define htons(x) (x)
+#undef htonl
 #define htonl(x) (x)
 #endif
 
