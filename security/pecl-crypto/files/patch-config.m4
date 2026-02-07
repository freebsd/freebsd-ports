--- config.m4.orig	2015-11-15 21:36:25 UTC
+++ config.m4
@@ -17,6 +17,8 @@ if test "$PHP_CRYPTO" != "no"; then
       PHP_ADD_INCLUDE($OPENSSL_INCDIR)
       CRYPTO_LIBS=`$PKG_CONFIG --libs openssl`
       PHP_EVAL_LIBLINE($CRYPTO_LIBS, CRYPTO_SHARED_LIBADD)
+    else
+      PHP_EVAL_LIBLINE("-lssl -lcrypto", CRYPTO_SHARED_LIBADD)
     fi
 
     AC_DEFINE(HAVE_CRYPTOLIB,1,[Enable objective OpenSSL Crypto wrapper])
