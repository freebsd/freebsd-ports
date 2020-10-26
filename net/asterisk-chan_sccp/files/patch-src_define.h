--- src/define.h.orig	2020-10-24 14:42:40 UTC
+++ src/define.h
@@ -98,10 +98,10 @@ SCCP_LINE unsigned long long ___bswap_64(unsigned long
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
 
