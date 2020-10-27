--- dh.cpp.orig	2015-11-28 22:51:00 UTC
+++ dh.cpp
@@ -148,11 +148,7 @@ openssl_unique_ptr<DH> make_dh (const unsigned char* p
 		throw Openssl_error(ERR_get_error());
 	}
 
-	if ((dh->p = BN_bin2bn(prime, prime_len, NULL)) == NULL) {
-		throw Openssl_error(ERR_get_error());
-	}
-
-	if ((dh->g = BN_bin2bn(generator, generator_len, NULL)) == NULL) {
+	if (!DH_set0_pqg(dh.get(), BN_bin2bn(prime, prime_len, NULL), NULL, BN_bin2bn(generator, generator_len, NULL))) {
 		throw Openssl_error(ERR_get_error());
 	}
 
