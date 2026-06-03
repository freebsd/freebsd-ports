diff --git plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig plugins/preauth/pkinit/pkinit_crypto_openssl.c
index 11c570f..cba4515 100644
--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c
@@ -787,6 +787,10 @@ oerr(krb5_context context, krb5_error_code code, const char *fmt, ...)
     return code;
 }
 
+#if defined(LIBRESSL_VERSION_NUMBER) && !defined(static_ASN1_SEQUENCE_END_name)
+#define static_ASN1_SEQUENCE_END_name	ASN1_SEQUENCE_END_name
+#endif
+
 /*
  * Set an appropriate error string containing msg for a certificate
  * verification failure from certctx.  Write the message and all pending
