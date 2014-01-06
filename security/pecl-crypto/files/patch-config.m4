--- ./config.m4.orig	2014-01-06 13:47:54.000000000 +0800
+++ ./config.m4	2014-01-06 13:48:11.000000000 +0800
@@ -17,6 +17,8 @@
       PHP_ADD_INCLUDE($OPENSSL_INCDIR)
       CRYPTO_LIBS=`$PKG_CONFIG --libs openssl`
       PHP_EVAL_LIBLINE($CRYPTO_LIBS, CRYPTO_SHARED_LIBADD)
+    else
+      PHP_EVAL_LIBLINE("-lssl -lcrypto", CRYPTO_SHARED_LIBADD)
     fi
 
     AC_DEFINE(HAVE_CRYPTOLIB,1,[Enable objective OpenSSL Crypto wrapper])
