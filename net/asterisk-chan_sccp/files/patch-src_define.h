--- src/define.h.orig	2020-02-04 11:13:32 UTC
+++ src/define.h
@@ -103,10 +103,10 @@ SCCP_LINE unsigned long long __bswap_64(unsigned long 
 #define htolel(x) (x)
 #define htoles(x) (x)
 #else
-#define letohs(x) __bswap_16(x)
-#define htoles(x) __bswap_16(x)
-#define letohl(x) __bswap_32(x)
-#define htolel(x) __bswap_32(x)
+#define letohs(x) bswap16(x)
+#define htoles(x) bswap16(x)
+#define letohl(x) bswap32(x)
+#define htolel(x) bswap32(x)
 #endif
 
 #define SCCP_TECHTYPE_STR "SCCP"
