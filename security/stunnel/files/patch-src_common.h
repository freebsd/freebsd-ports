--- src/common.h.orig	2016-06-27 07:29:32 UTC
+++ src/common.h
@@ -415,6 +415,10 @@ extern char *sys_errlist[];
 /* opensslv.h requires prior opensslconf.h to include -fips in version string */
 #include <openssl/opensslv.h>
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#define OPENSSL_VERSION_NUMBER 0x1000107fL
+#endif
+
 #if OPENSSL_VERSION_NUMBER<0x0090700fL
 #error OpenSSL 0.9.7 or later is required
 #endif /* OpenSSL older than 0.9.7 */
