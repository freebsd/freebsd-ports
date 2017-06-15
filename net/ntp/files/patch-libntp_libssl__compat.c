--- libntp/libssl_compat.c.orig	2017-02-01 01:47:13.000000000 -0800
+++ libntp/libssl_compat.c	2017-03-22 22:29:56.409257000 -0700
@@ -26,7 +26,7 @@
 /* ----------------------------------------------------------------- */
 
 /* ----------------------------------------------------------------- */
-#if defined(OPENSSL) && OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(OPENSSL) && (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
 /* ----------------------------------------------------------------- */
 
 #include "libssl_compat.h"
