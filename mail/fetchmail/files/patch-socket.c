FreeBSD's security team needs to maintain OpenSSL 1.1.1's
security to a sane level without upstream support... but permit the build
for FreeBSD 13.3 and 13.4:

--- socket.c.orig	2024-09-28 09:20:10 UTC
+++ socket.c
@@ -375,7 +375,7 @@ enum { SSL_min_security_level = 2 };
 # ifndef TLSprovider
 #  define TLSprovider "OpenSSL"
 # endif
-# define fm_MIN_OPENSSL_VER 0x30000090L
+# define fm_MIN_OPENSSL_VER 0x1010117fL
 /* do not warn about OpenSSL 3.2.0, the 3.2.1 fix is of low priority */
 # if OPENSSL_VERSION_NUMBER >= 0x30100000L && OPENSSL_VERSION_NUMBER < 0x30200000L
 #  if OPENSSL_VERSION_NUMBER < 0x30100040L
