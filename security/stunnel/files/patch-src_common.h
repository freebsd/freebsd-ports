--- src/common.h.orig	2017-01-02 14:27:26 UTC
+++ src/common.h
@@ -415,6 +415,15 @@ extern char *sys_errlist[];
 /* opensslv.h requires prior opensslconf.h to include -fips in version string */
 #include <openssl/opensslv.h>
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#undef OPENSSL_VERSION_NUMBER
+#if LIBRESSL_VERSION_NUMBER >= 0x2070000fL
+#define OPENSSL_VERSION_NUMBER 0x10100000L
+#else
+#define OPENSSL_VERSION_NUMBER 0x1000107fL
+#endif
+#endif
+
 #if OPENSSL_VERSION_NUMBER<0x0090700fL
 #error OpenSSL 0.9.7 or later is required
 #endif /* OpenSSL older than 0.9.7 */
