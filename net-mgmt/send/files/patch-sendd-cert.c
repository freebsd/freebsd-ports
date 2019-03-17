--- sendd/cert.c.orig	2019-02-27 16:25:45 UTC
+++ sendd/cert.c
@@ -73,7 +73,11 @@ get_pubkeyhash(X509 *x, uint8_t *buf)
 	EVP_PKEY *k;
 	int dlen;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	k = X509_PUBKEY_get(x->cert_info->key);
+#else
+	k = X509_get_pubkey(x);
+#endif
 	if ((der = cga_key2der(k, &dlen)) == NULL) {
 		return (-1);
 	}
