--- third_party/grpc/src/src/core/lib/security/credentials/jwt/jwt_verifier.c.orig	2018-12-27 21:47:56 UTC
+++ third_party/grpc/src/src/core/lib/security/credentials/jwt/jwt_verifier.c
@@ -467,6 +467,7 @@ static EVP_PKEY *pkey_from_jwk(const grp
   const grpc_json *key_prop;
   RSA *rsa = NULL;
   EVP_PKEY *result = NULL;
+  BIGNUM *ee = NULL, *nn = NULL;
 
   GPR_ASSERT(kty != NULL && json != NULL);
   if (strcmp(kty, "RSA") != 0) {
@@ -480,14 +481,29 @@ static EVP_PKEY *pkey_from_jwk(const grp
   }
   for (key_prop = json->child; key_prop != NULL; key_prop = key_prop->next) {
     if (strcmp(key_prop->key, "n") == 0) {
-      rsa->n = bignum_from_base64(validate_string_field(key_prop, "n"));
-      if (rsa->n == NULL) goto end;
+      BIGNUM *n = bignum_from_base64(validate_string_field(key_prop, "n"));
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+      rsa->n = n;
+#else
+      RSA_set0_key(rsa, &n, NULL, NULL);
+#endif
+      if (n == NULL) goto end;
     } else if (strcmp(key_prop->key, "e") == 0) {
-      rsa->e = bignum_from_base64(validate_string_field(key_prop, "e"));
-      if (rsa->e == NULL) goto end;
+      BIGNUM *e = bignum_from_base64(validate_string_field(key_prop, "e"));
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+      rsa->e = e;
+#else
+      RSA_set0_key(rsa, NULL, &e, NULL);
+#endif
+      if (e == NULL) goto end;
     }
   }
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   if (rsa->e == NULL || rsa->n == NULL) {
+#else
+  RSA_get0_key(rsa, &nn, &ee, NULL);
+  if (ee == NULL || nn == NULL) {
+#endif
     gpr_log(GPR_ERROR, "Missing RSA public key field.");
     goto end;
   }
