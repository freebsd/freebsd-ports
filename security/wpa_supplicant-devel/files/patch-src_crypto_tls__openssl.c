--- src/crypto/tls_openssl.c.orig	2026-11-23 04:04:17.000000000 -0700
+++ src/crypto/tls_openssl.c	2026-11-25 10:30:08.602605000 -0700
@@ -7,13 +7,9 @@
  */
 
 #include "includes.h"
-#ifdef CONFIG_TLS_ENGINE_TRUSTED_PATH
 #include <sys/stat.h>
 #include <limits.h>
-#endif /* CONFIG_TLS_ENGINE_TRUSTED_PATH */
-#ifdef CONFIG_TESTING_OPTIONS
 #include <fcntl.h>
-#endif /* CONFIG_TESTING_OPTIONS */
 
 #ifndef CONFIG_SMARTCARD
 #ifndef OPENSSL_NO_ENGINE
