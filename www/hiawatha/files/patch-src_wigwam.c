--- src/wigwam.c.orig	2022-06-29 09:42:42 UTC
+++ src/wigwam.c
@@ -582,7 +582,7 @@ int check_main_config(char *config_dir) {
 		/* Private key check
 		 */
 		mbedtls_pk_init(&private_key);
-		if (mbedtls_pk_parse_keyfile(&private_key, needle->value, NULL, mbedtls_psa_get_random, MBEDTLS_PSA_RANDOM_STATE) != 0) {
+		if (mbedtls_pk_parse_keyfile(&private_key, needle->value, NULL) != 0) {
 			printf("Error loading private key from %s.\n", needle->value);
 			errors++;
 			goto next_crt;
@@ -601,7 +601,7 @@ int check_main_config(char *config_dir) {
 			goto next_crt;
 		}
 
-		if (certificate.MBEDTLS_PRIVATE(sig_md) < MBEDTLS_MD_SHA256) {
+		if (certificate.sig_md < MBEDTLS_MD_SHA256) {
 			printf("Warning: the certificate signature algoritm in %s should at least be SHA256.\n", needle->value);
 		}
 
