--- lib/pkcs11.cpp.orig	2021-05-07 20:40:29 UTC
+++ lib/pkcs11.cpp
@@ -840,8 +840,7 @@ EVP_PKEY *pkcs11::getPrivateKey(EVP_PKEY *pub, CK_OBJE
 
 	switch (EVP_PKEY_type(keytype)) {
 	case EVP_PKEY_RSA:
-		rsa = EVP_PKEY_get0_RSA(pub);
-		rsa = RSAPublicKey_dup(rsa);
+		rsa = RSAPublicKey_dup(EVP_PKEY_get0_RSA(pub));
 		openssl_error();
 		if (!rsa_meth) {
 #if OPENSSL_VERSION_NUMBER >= 0x1010000L
@@ -865,8 +864,7 @@ EVP_PKEY *pkcs11::getPrivateKey(EVP_PKEY *pub, CK_OBJE
 		EVP_PKEY_assign_RSA(evp, rsa);
 		break;
 	case EVP_PKEY_DSA:
-		dsa = EVP_PKEY_get0_DSA(pub);
-		dsa = DSAparams_dup(dsa);
+		dsa = DSAparams_dup(EVP_PKEY_get0_DSA(pub));
 		openssl_error();
 		if (!dsa_meth) {
 #if OPENSSL_VERSION_NUMBER >= 0x10100000L
@@ -889,8 +887,7 @@ EVP_PKEY *pkcs11::getPrivateKey(EVP_PKEY *pub, CK_OBJE
 		break;
 #if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x10100000L
 	case EVP_PKEY_EC:
-		ec = EVP_PKEY_get0_EC_KEY(pub);
-		ec = EC_KEY_dup(ec);
+		ec = EC_KEY_dup(EVP_PKEY_get0_EC_KEY(pub));
 		openssl_error();
 		if (!ec_key_meth) {
 			ec_key_meth = setup_ec_key_meth();
