--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig	2025-08-05 14:15:15 UTC
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c
@@ -201,6 +201,17 @@ create_identifiers_from_stack(STACK_OF(X509) *sk,
 create_identifiers_from_stack(STACK_OF(X509) *sk,
                               krb5_external_principal_identifier *** ids);
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+
+/*
+ * 1.1 adds DHX support, which uses the RFC 3279 DomainParameters encoding we
+ * need for PKINIT.  For 1.0 we must use the original DH type when creating
+ * EVP_PKEY objects.
+ */
+#define EVP_PKEY_DHX EVP_PKEY_DH
+#define d2i_DHxparams d2i_DHparams
+#endif
+
 #if OPENSSL_VERSION_NUMBER < 0x10100000L
 
 /* 1.1 standardizes constructor and destructor names, renaming
@@ -210,13 +221,6 @@ create_identifiers_from_stack(STACK_OF(X509) *sk,
 #define EVP_MD_CTX_free EVP_MD_CTX_destroy
 #define ASN1_STRING_get0_data ASN1_STRING_data
 
-/*
- * 1.1 adds DHX support, which uses the RFC 3279 DomainParameters encoding we
- * need for PKINIT.  For 1.0 we must use the original DH type when creating
- * EVP_PKEY objects.
- */
-#define EVP_PKEY_DHX EVP_PKEY_DH
-
 /* 1.1 makes many handle types opaque and adds accessors.  Add compatibility
  * versions of the new accessors we use for pre-1.1. */
 
@@ -657,7 +661,7 @@ set_padded_derivation(EVP_PKEY_CTX *ctx)
 {
     EVP_PKEY_CTX_set_dh_pad(ctx, 1);
 }
-#elif OPENSSL_VERSION_NUMBER >= 0x10100000L
+#elif OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 static void
 set_padded_derivation(EVP_PKEY_CTX *ctx)
 {
