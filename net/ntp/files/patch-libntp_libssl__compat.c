--- libntp/libssl_compat.c.orig	2016-11-21 12:28:40 UTC
+++ libntp/libssl_compat.c
@@ -23,7 +23,7 @@
 #include "ntp_types.h"
 
 /* ----------------------------------------------------------------- */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* ----------------------------------------------------------------- */
 
 #include "libssl_compat.h"
