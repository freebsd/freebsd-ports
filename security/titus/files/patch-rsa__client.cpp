--- rsa_client.cpp.orig	2015-11-28 22:51:00 UTC
+++ rsa_client.cpp
@@ -85,7 +85,7 @@ int	Rsa_client::rsa_private_encrypt (int flen, const u
 int	Rsa_client::rsa_finish (RSA* rsa)
 {
 	delete reinterpret_cast<Rsa_client_data*>(RSA_get_app_data(rsa));
-	if (const auto default_finish = RSA_get_default_method()->finish) {
+	if (const auto default_finish = RSA_meth_get_finish(RSA_get_default_method())) {
 		return (*default_finish)(rsa);
 	} else {
 		return 1;
@@ -94,14 +94,14 @@ int	Rsa_client::rsa_finish (RSA* rsa)
 
 const RSA_METHOD*	Rsa_client::get_rsa_method ()
 {
-	static RSA_METHOD ops;
-	if (!ops.rsa_priv_enc) {
-		ops = *RSA_get_default_method();
-		ops.rsa_priv_enc = rsa_private_encrypt;
-		ops.rsa_priv_dec = rsa_private_decrypt;
-		ops.finish = rsa_finish;
+	static RSA_METHOD* ops = NULL;
+	if (ops == NULL) {
+		ops = RSA_meth_dup(RSA_get_default_method());
+		RSA_meth_set_priv_enc(ops, rsa_private_encrypt);
+		RSA_meth_set_priv_dec(ops, rsa_private_decrypt);
+		RSA_meth_set_finish(ops, rsa_finish);
 	}
-	return &ops;
+	return ops;
 }
 
 openssl_unique_ptr<EVP_PKEY>	Rsa_client::load_private_key (uintptr_t key_id, RSA* public_rsa)
@@ -111,12 +111,10 @@ openssl_unique_ptr<EVP_PKEY>	Rsa_client::load_private_
 		throw Openssl_error(ERR_get_error());
 	}
 
-	rsa->n = BN_dup(public_rsa->n);
-	if (!rsa->n) {
-		throw Openssl_error(ERR_get_error());
-	}
-	rsa->e = BN_dup(public_rsa->e);
-	if (!rsa->e) {
+	const BIGNUM* n;
+	const BIGNUM* e;
+	RSA_get0_key(public_rsa, &n, &e, NULL);
+	if (!RSA_set0_key(rsa.get(), BN_dup(n), BN_dup(e), NULL)) {
 		throw Openssl_error(ERR_get_error());
 	}
 
