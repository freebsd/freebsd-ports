--- lib/pki_key.cpp.orig	2021-05-07 20:40:29 UTC
+++ lib/pki_key.cpp
@@ -197,7 +197,7 @@ QString pki_key::length() const
 
 	if (EVP_PKEY_id(key) == EVP_PKEY_DSA) {
 		const BIGNUM *p = NULL;
-		DSA *dsa = EVP_PKEY_get0_DSA(key);
+		const DSA *dsa = EVP_PKEY_get0_DSA(key);
 		if (dsa)
 			DSA_get0_pqg(dsa, &p, NULL, NULL);
 		dsa_unset = p == NULL;
@@ -299,7 +299,7 @@ QString pki_key::modulus() const
 	if (getKeyType() == EVP_PKEY_RSA) {
 		const BIGNUM *n = NULL;
 
-		RSA *rsa = EVP_PKEY_get0_RSA(key);
+		const RSA *rsa = EVP_PKEY_get0_RSA(key);
 		RSA_get0_key(rsa, &n, NULL, NULL);
 		return BN2QString(n);
 	}
@@ -310,7 +310,7 @@ QString pki_key::pubEx() const
 {
 	if (getKeyType() == EVP_PKEY_RSA) {
 		const BIGNUM *e = NULL;
-		RSA *rsa = EVP_PKEY_get0_RSA(key);
+		const RSA *rsa = EVP_PKEY_get0_RSA(key);
 		RSA_get0_key(rsa, NULL, &e, NULL);
 		return BN2QString(e);
 	}
@@ -321,7 +321,7 @@ QString pki_key::subprime() const
 {
 	if (getKeyType() == EVP_PKEY_DSA) {
 		const BIGNUM *q = NULL;
-		DSA *dsa = EVP_PKEY_get0_DSA(key);
+		const DSA *dsa = EVP_PKEY_get0_DSA(key);
 		if (dsa)
 			DSA_get0_pqg(dsa, NULL, &q, NULL);
 		return BN2QString(q);
@@ -333,7 +333,7 @@ QString pki_key::pubkey() const
 {
 	if (getKeyType() == EVP_PKEY_DSA) {
 		const BIGNUM *pubkey = NULL;
-		DSA *dsa = EVP_PKEY_get0_DSA(key);
+		const DSA *dsa = EVP_PKEY_get0_DSA(key);
 		if (dsa)
 			DSA_get0_key(dsa, &pubkey, NULL);
 		return BN2QString(pubkey);
@@ -766,7 +766,7 @@ QByteArray pki_key::SSH2publicQByteArray(bool raw) con
 		txt = "ssh-rsa";
 		ssh_key_QBA2data(txt, &data);
 		{
-			RSA *rsa = EVP_PKEY_get0_RSA(key);
+			const RSA *rsa = EVP_PKEY_get0_RSA(key);
 			const BIGNUM *n, *e;
 			RSA_get0_key(rsa, &n, &e, NULL);
 			ssh_key_bn2data(e, &data);
@@ -777,7 +777,7 @@ QByteArray pki_key::SSH2publicQByteArray(bool raw) con
 		txt = "ssh-dss";
 		ssh_key_QBA2data(txt, &data);
 		{
-			DSA *dsa = EVP_PKEY_get0_DSA(key);
+			const DSA *dsa = EVP_PKEY_get0_DSA(key);
 			const BIGNUM *p, *q, *g, *pubkey;
 			DSA_get0_pqg(dsa, &p, &q, &g);
 			DSA_get0_key(dsa, &pubkey, NULL);
