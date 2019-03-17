--- libs/libcga/cga_keyutils.c.orig	2019-02-27 16:25:45 UTC
+++ libs/libcga/cga_keyutils.c
@@ -45,6 +45,7 @@
 #include <pthread.h>
 #include <openssl/err.h>
 #include <openssl/pem.h>
+#include <openssl/x509.h>
 
 #include "config.h"
 #include <applog.h>
@@ -80,7 +81,7 @@ cga_load_cert(cga_ctx_t *cga, const char *f)
 		goto fail;
 	}
 
-	k = X509_PUBKEY_get(x->cert_info->key);
+	k = X509_PUBKEY_get(X509_get_X509_PUBKEY(x));
 
 	if (cga->key && cga->free_key) {
 		free(cga->key);
