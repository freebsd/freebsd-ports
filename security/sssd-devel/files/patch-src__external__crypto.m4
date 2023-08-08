--- src/external/crypto.m4.orig	2023-05-05 08:11:07 UTC
+++ src/external/crypto.m4
@@ -1,6 +1,15 @@
-AC_DEFUN([AM_CHECK_LIBCRYPTO],
-         [PKG_CHECK_MODULES([CRYPTO],[libcrypto])
-          PKG_CHECK_MODULES([SSL],[libssl])
+CRYPTO_CFLAGS="-I/usr/include"
+CRYPTO_LIBS="-L/usr/lib -lcrypto"
+AC_SUBST(CRYPTO_CFLAGS)
+AC_SUBST(CRYPTO_LIBS)
+
+SSL_CFLAGS="-I/usr/include"
+SSL_LIBS="-L/usr/lib -lssl"
+AC_SUBST(SSL_CFLAGS)
+AC_SUBST(SSL_LIBS)
+
+AC_DEFUN([AM_CHECK_LIBCRYPTO], [
+	AC_MSG_RESULT([yes])
 ])
 
 AC_MSG_CHECKING([whether OpenSSL's x400Address is ASN1_STRING])
