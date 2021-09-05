--- libraries/libldap/tls_o.c.orig	2021-07-27 17:44:47 UTC
+++ libraries/libldap/tls_o.c
@@ -275,7 +275,7 @@ tlso_ctx_free ( tls_ctx *ctx )
 	SSL_CTX_free( c );
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000
+#if OPENSSL_VERSION_NUMBER >= 0x10101000 && !defined(OPENSSL_NO_TLS1_3)
 static char *
 tlso_stecpy( char *dst, const char *src, const char *end )
 {
@@ -411,7 +411,7 @@ tlso_ctx_init( struct ldapoptions *lo, struct ldaptls 
 	}
 
 	if ( lo->ldo_tls_ciphersuite ) {
-#if OPENSSL_VERSION_NUMBER >= 0x10101000
+#if OPENSSL_VERSION_NUMBER >= 0x10101000 && !defined(OPENSSL_NO_TLS1_3)
 		tlso_ctx_cipher13( ctx, lt->lt_ciphersuite );
 #endif
 		if ( !SSL_CTX_set_cipher_list( ctx, lt->lt_ciphersuite ) )
