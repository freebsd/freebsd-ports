Many applications use checking of OPENSSL_VERSION to detect if
a feature is available and thus fail to build when the version
is set to 0x20000000L. This fixes the OPENSSL_VERSION to the
time at which LibreSSL forked.

--- include/openssl/opensslv.h.orig	2015-09-11 22:35:14 UTC
+++ include/openssl/opensslv.h
@@ -7,7 +7,7 @@
 #define LIBRESSL_VERSION_TEXT	"LibreSSL 2.3.0"
 
 /* These will never change */
-#define OPENSSL_VERSION_NUMBER	0x20000000L
+#define OPENSSL_VERSION_NUMBER	0x1000107fL
 #define OPENSSL_VERSION_TEXT	LIBRESSL_VERSION_TEXT
 #define OPENSSL_VERSION_PTEXT	" part of " OPENSSL_VERSION_TEXT
 
