--- lib/pki_evp.cpp.orig	2021-05-07 20:40:29 UTC
+++ lib/pki_evp.cpp
@@ -282,8 +282,8 @@ static void search_ec_oid(EVP_PKEY *pkey)
 static void search_ec_oid(EVP_PKEY *pkey)
 {
 #ifndef OPENSSL_NO_EC
-	EC_KEY *ec;
 	EC_GROUP *builtin;
+	const EC_KEY *ec;
 	const EC_GROUP *ec_group;
 
 	int keytype = EVP_PKEY_id(pkey);
@@ -621,8 +621,10 @@ EVP_PKEY *pki_evp::legacyDecryptKey(QByteArray &myencK
 
 	pki_openssl_error();
 	if (EVP_PKEY_type(getKeyType()) == EVP_PKEY_RSA) {
-		RSA *rsa = EVP_PKEY_get0_RSA(tmpkey);
+		RSA *rsa = (RSA *)EVP_PKEY_get0_RSA(tmpkey);
+#if OPENSSL_VERSION_MAJOR < 3
 		RSA_blinding_on(rsa, NULL);
+#endif
 	}
 	myencKey.fill(0);
 	return tmpkey;
@@ -930,7 +932,7 @@ bool pki_evp::verify_priv(EVP_PKEY *pkey) const
 		EVP_MD_CTX_free(ctx);
 #endif
 	if (EVP_PKEY_id(pkey) == EVP_PKEY_RSA && EVP_PKEY_isPrivKey(pkey)) {
-		RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+		const RSA *rsa = EVP_PKEY_get0_RSA(pkey);
 		if (RSA_check_key(rsa) != 1)
 			verify = false;
 	}
