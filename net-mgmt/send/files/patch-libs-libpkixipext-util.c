--- libs/libpkixipext/util.c.orig	2019-02-27 16:25:45 UTC
+++ libs/libpkixipext/util.c
@@ -37,8 +37,13 @@
 #include "config.h"
 #include "pkixip_ext_asn.h"
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 int
 pkixip_aor_cmp(const char * const *a1, const char * const *a2)
+#else
+int
+pkixip_aor_cmp(const IPAddressOrRange * const *a1, const IPAddressOrRange * const *a2)
+#endif
 {
 	int by1, by2, bi1, bi2, bytes, bits;
 	uint8_t *d1, *d2, x1, x2, mask;
@@ -119,8 +124,13 @@ pkixip_aor_cmp(const char * const *a1, const char * co
 	return (0);
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 int
 pkixip_ipf_cmp(const char * const *a1, const char * const *a2)
+#else
+int
+pkixip_ipf_cmp(const IPAddressFamily * const *a1, const IPAddressFamily * const *a2)
+#endif
 {
 	IPAddressFamily *ipf1 = (IPAddressFamily *)*a1;
 	IPAddressFamily *ipf2 = (IPAddressFamily *)*a2;
