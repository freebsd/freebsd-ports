--- src/tls.c.orig	2022-01-22 12:16:26 UTC
+++ src/tls.c
@@ -322,7 +322,7 @@ int tls_load_key_cert(char *file, mbedtls_pk_context *
 	}
 	mbedtls_pk_init(*private_key);
 
-	if ((result = mbedtls_pk_parse_keyfile(*private_key, file, NULL, mbedtls_psa_get_random, MBEDTLS_PSA_RANDOM_STATE)) != 0) {
+	if ((result = mbedtls_pk_parse_keyfile(*private_key, file, NULL)) != 0) {
 		print_tls_error(result, "Error loading private key from %s", file);
 		return -1;
 	}
@@ -436,11 +436,13 @@ int tls_accept(int *sock, mbedtls_ssl_context *context
 
 	result = TLS_HANDSHAKE_OKE;
 	while ((handshake = mbedtls_ssl_handshake(context)) != 0) {
+#ifndef __FreeBSD__
 		if (handshake == MBEDTLS_ERR_SSL_HANDSHAKE_FAILURE) {
 			mbedtls_ssl_free(context);
 			result = TLS_HANDSHAKE_NO_MATCH;
 			break;
 		}
+#endif
 
 		if ((handshake != MBEDTLS_ERR_SSL_WANT_READ) && (handshake != MBEDTLS_ERR_SSL_WANT_WRITE)) {
 			mbedtls_ssl_free(context);
