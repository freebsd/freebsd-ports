--- libfreerdp/core/certificate.c.orig	2014-09-11 22:46:32 UTC
+++ libfreerdp/core/certificate.c
@@ -32,6 +32,7 @@
 #include <openssl/rsa.h>
 
 #include "certificate.h"
+#include "../crypto/opensslcompat.h"
 
 #define TAG "com.freerdp.core"
 
@@ -652,6 +653,9 @@ rdpRsaKey* key_new(const char* keyfile)
 	FILE* fp;
 	RSA* rsa;
 	rdpRsaKey* key;
+	const BIGNUM *rsa_e = NULL;
+	const BIGNUM *rsa_n = NULL;
+	const BIGNUM *rsa_d = NULL;
 	key = (rdpRsaKey*)calloc(1, sizeof(rdpRsaKey));
 
 	if (!key)
@@ -692,31 +696,31 @@ rdpRsaKey* key_new(const char* keyfile)
 			ERR_print_errors_fp(stderr);
 			goto out_free_rsa;
 	}
-
-	if (BN_num_bytes(rsa->e) > 4)
+	RSA_get0_key(rsa, &rsa_n, &rsa_e, &rsa_d);
+	if (BN_num_bytes(rsa_e) > 4)
 	{
 		DEBUG_WARN("%s: RSA public exponent too large in %s\n", __FUNCTION__, keyfile);
 		goto out_free_rsa;
 	}
 
-	key->ModulusLength = BN_num_bytes(rsa->n);
+	key->ModulusLength = BN_num_bytes(rsa_n);
 	key->Modulus = (BYTE*)malloc(key->ModulusLength);
 
 	if (!key->Modulus)
 		goto out_free_rsa;
 
-	BN_bn2bin(rsa->n, key->Modulus);
+	BN_bn2bin(rsa_n, key->Modulus);
 	crypto_reverse(key->Modulus, key->ModulusLength);
-	key->PrivateExponentLength = BN_num_bytes(rsa->d);
+	key->PrivateExponentLength = BN_num_bytes(rsa_d);
 	key->PrivateExponent = (BYTE*)malloc(key->PrivateExponentLength);
 
 	if (!key->PrivateExponent)
 		goto out_free_modulus;
 
-	BN_bn2bin(rsa->d, key->PrivateExponent);
+	BN_bn2bin(rsa_d, key->PrivateExponent);
 	crypto_reverse(key->PrivateExponent, key->PrivateExponentLength);
 	memset(key->exponent, 0, sizeof(key->exponent));
-	BN_bn2bin(rsa->e, key->exponent + sizeof(key->exponent) - BN_num_bytes(rsa->e));
+	BN_bn2bin(rsa_e, key->exponent + sizeof(key->exponent) - BN_num_bytes(rsa_e));
 	crypto_reverse(key->exponent, sizeof(key->exponent));
 	RSA_free(rsa);
 	return key;
