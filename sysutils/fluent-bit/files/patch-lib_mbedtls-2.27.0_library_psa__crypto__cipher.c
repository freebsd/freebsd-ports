--- /dev/null	
+++ b/sysutils/fluent-bit/files/patch-lib_mbedtls-2.27.0_library_psa__crypto__cipher.c	
@@ -0,0 +1,11 @@ 
+--- lib/mbedtls-2.27.0/library/psa_crypto_cipher.c.orig	2022-04-04 06:45:04 UTC
++++ lib/mbedtls-2.27.0/library/psa_crypto_cipher.c
+@@ -267,7 +267,7 @@ static psa_status_t psa_cipher_update_ecb(
+     const uint8_t *input,
+     size_t input_length,
+     uint8_t *output,
+-    size_t output_size,
++    size_t output_size __attribute__((unused)),
+     size_t *output_length )
+ {
+     psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
