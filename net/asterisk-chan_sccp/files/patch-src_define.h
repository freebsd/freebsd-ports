--- src/define.h.orig	2021-12-29 10:49:04 UTC
+++ src/define.h
@@ -96,10 +96,10 @@ SCCP_LINE unsigned long long ___bswap_64(unsigned long
 #    define htolel(x) (uint16_t)(x)
 #    define htoles(x) (uint16_t)(x)
 #  else
-#    define letohs(x) ___bswap_16(x)
-#    define htoles(x) ___bswap_16(x)
-#    define letohl(x) ___bswap_32(x)
-#    define htolel(x) ___bswap_32(x)
+#    define letohs(x) bswap16(x)
+#    define htoles(x) bswap16(x)
+#    define letohl(x) bswap32(x)
+#    define htolel(x) bswap32(x)
 #  endif
 #endif
 
