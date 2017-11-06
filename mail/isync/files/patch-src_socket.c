--- src/socket.c.orig	2017-08-13 23:04:40 UTC
+++ src/socket.c
@@ -40,7 +40,7 @@
 # include <openssl/ssl.h>
 # include <openssl/err.h>
 # include <openssl/x509v3.h>
-# if OPENSSL_VERSION_NUMBER < 0x10100000L
+# if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #  define X509_OBJECT_get0_X509(o) ((o)->data.x509)
 #  define X509_STORE_get0_objects(o) ((o)->objs)
 # endif
