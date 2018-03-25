--- source4/dsdb/samdb/ldb_modules/encrypted_secrets.c.orig	2018-03-01 22:18:10 UTC
+++ source4/dsdb/samdb/ldb_modules/encrypted_secrets.c
@@ -750,16 +750,16 @@ static struct ldb_val gnutls_encrypt_aea
 	 * Encrypt the value.
 	 */
 	{
-		size_t el;
-		const unsigned block_size = gnutls_cipher_get_tag_size(
+		const unsigned block_size = gnutls_cipher_get_block_size(
 			data->encryption_algorithm);
-		const unsigned tag_size = gnutls_cipher_get_block_size(
+		const unsigned tag_size = gnutls_cipher_get_tag_size(
 			data->encryption_algorithm);
 		const size_t ed_size = round_to_block_size(
 			block_size,
 			sizeof(struct PlaintextSecret) + val.length);
 		const size_t en_size = ed_size + tag_size;
 		uint8_t *ct = talloc_zero_size(frame, en_size);
+		size_t el = en_size;
 
 		if (ct == NULL) {
 			ldb_set_errstring(ldb,
