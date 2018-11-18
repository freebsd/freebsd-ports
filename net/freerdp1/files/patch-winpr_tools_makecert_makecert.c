--- winpr/tools/makecert/makecert.c.orig	2018-11-06 05:00:05 UTC
+++ winpr/tools/makecert/makecert.c
@@ -27,6 +27,7 @@
 #include <winpr/cmdline.h>
 #include <winpr/sysinfo.h>
 
+#include <openssl/crypto.h>
 #include <openssl/conf.h>
 #include <openssl/pem.h>
 #include <openssl/err.h>
@@ -757,7 +758,6 @@ void makecert_context_free(MAKECERT_CONTEXT* context)
 
 		CRYPTO_cleanup_all_ex_data();
 
-		CRYPTO_mem_leaks(context->bio);
 		BIO_free(context->bio);
 
 		free(context);
