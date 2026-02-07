--- src/gnutls_sni.c.orig	2019-01-28 19:50:38 UTC
+++ src/gnutls_sni.c
@@ -18,7 +18,12 @@
 
 #include <apr_lib.h>
 #include <apr_strings.h>
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#else
 #include <byteswap.h>
+#endif
 #include <gnutls/gnutls.h>
 #include <inttypes.h>
 
