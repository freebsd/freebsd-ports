--- src/common/tls.c.orig	2018-10-10 00:47:13 UTC
+++ src/common/tls.c
@@ -102,6 +102,7 @@
 #include <ev.h>
 #include <openssl/conf.h>
 #include <openssl/err.h>
+#include <openssl/opensslv.h>
 #include <openssl/ssl.h>
 
 #include "log.h"
@@ -419,7 +420,9 @@ initialize_openssl(const SSL_METHOD *method, const cha
 
 	(void)SSL_library_init();
 	SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	(void)atexit(ERR_free_strings);
+#endif
 
 	/*
 	 * In earlier versions, we called
