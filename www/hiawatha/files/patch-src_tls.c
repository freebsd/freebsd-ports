--- src/tls.c.orig	2022-01-22 12:16:26 UTC
+++ src/tls.c
@@ -161,7 +161,7 @@ int init_tls_module(mbedtls_x509_crt *ca_certificates)
 int init_tls_module(mbedtls_x509_crt *ca_certificates) {
 	char version[16];
 
-	if (mbedtls_version_get_number() < 0x03000000) {
+	if (mbedtls_version_get_number() < 0x021c0000) {
 		mbedtls_version_get_string(version);
 		fprintf(stderr, "This Hiawatha installation requires at least mbed TLS v3.0.0 and you have v%s.\n", version);
 		return -1;
@@ -322,7 +322,7 @@ int tls_load_key_cert(char *file, mbedtls_pk_context *
 	}
 	mbedtls_pk_init(*private_key);
 
-	if ((result = mbedtls_pk_parse_keyfile(*private_key, file, NULL, mbedtls_psa_get_random, MBEDTLS_PSA_RANDOM_STATE)) != 0) {
+	if ((result = mbedtls_pk_parse_keyfile(*private_key, file, NULL)) != 0) {
 		print_tls_error(result, "Error loading private key from %s", file);
 		return -1;
 	}
@@ -436,7 +436,7 @@ int tls_accept(int *sock, mbedtls_ssl_context *context
 
 	result = TLS_HANDSHAKE_OKE;
 	while ((handshake = mbedtls_ssl_handshake(context)) != 0) {
-		if (handshake == MBEDTLS_ERR_SSL_HANDSHAKE_FAILURE) {
+		if (handshake == MBEDTLS_ERR_SSL_BAD_HS_PROTOCOL_VERSION) {
 			mbedtls_ssl_free(context);
 			result = TLS_HANDSHAKE_NO_MATCH;
 			break;
