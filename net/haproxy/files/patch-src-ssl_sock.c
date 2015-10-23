--- src/ssl_sock.c
+++ src/ssl_sock.c
@@ -1091,12 +1091,16 @@ ssl_sock_do_create_cert(const char *servername, unsigned int serial,
 	else if (EVP_PKEY_type (capkey->type) == EVP_PKEY_EC)
 		digest = EVP_sha256();
 	else {
+#if (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
 		int nid;
 
 		if (EVP_PKEY_get_default_digest_nid(capkey, &nid) <= 0)
 			goto mkcert_error;
 		if (!(digest = EVP_get_digestbynid(nid)))
 			goto mkcert_error;
+#else
+		goto mkcert_error;
+#endif
 	}
 
 	if (!(X509_sign(newcrt, capkey, digest)))
