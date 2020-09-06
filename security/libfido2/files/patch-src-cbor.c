Obtained from:	https://github.com/Yubico/libfido2/commit/e009c77b1fba57faf9524d3b788da2807b7406d8

--- src/cbor.c.orig	2020-09-01 07:17:43 UTC
+++ src/cbor.c
@@ -726,8 +726,8 @@ cbor_encode_change_pin_auth(const fido_blob_t *key, co
 
 	if ((md = EVP_sha256()) == NULL ||
 	    HMAC_Init_ex(&ctx, key->ptr, (int)key->len, md, NULL) == 0 ||
-	    HMAC_Update(&ctx, npe->ptr, (int)npe->len) == 0 ||
-	    HMAC_Update(&ctx, phe->ptr, (int)phe->len) == 0 ||
+	    HMAC_Update(&ctx, npe->ptr, npe->len) == 0 ||
+	    HMAC_Update(&ctx, phe->ptr, phe->len) == 0 ||
 	    HMAC_Final(&ctx, dgst, &dgst_len) == 0 || dgst_len != 32) {
 		fido_log_debug("%s: HMAC", __func__);
 		goto fail;
