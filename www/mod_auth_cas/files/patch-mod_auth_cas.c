--- ./mod_auth_cas.c.orig	2014-07-13 23:56:46.000000000 +0200
+++ ./mod_auth_cas.c	2014-07-13 23:58:26.000000000 +0200
@@ -2024,9 +2024,9 @@
 			CRYPTO_set_id_callback(cas_ssl_id_callback);
 		}
 #else
-		if(CRYPTO_get_locking_callback() == NULL && CRYPTO_THREADID_get_id_callback() == NULL) {
+		if(CRYPTO_get_locking_callback() == NULL && CRYPTO_THREADID_get_callback() == NULL) {
 			CRYPTO_set_locking_callback(cas_ssl_locking_callback);
-			CRYPTO_THREADID_set_id_callback(cas_ssl_id_callback);
+			CRYPTO_THREADID_set_callback(cas_ssl_id_callback);
 		}
 #endif /* OPENSSL_NO_THREADID */
 #endif /* defined(OPENSSL_THREADS) && APR_HAS_THREADS */
