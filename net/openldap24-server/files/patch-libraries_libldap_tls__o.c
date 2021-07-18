--- libraries/libldap/tls_o.c.orig	2021-06-03 18:40:31 UTC
+++ libraries/libldap/tls_o.c
@@ -273,7 +273,7 @@ tlso_ctx_free ( tls_ctx *ctx )
 	SSL_CTX_free( c );
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000
+#if OPENSSL_VERSION_NUMBER >= 0x10101000 && !defined(OPENSSL_NO_TLS1_3)
 static char *
 tlso_stecpy( char *dst, const char *src, const char *end )
 {
@@ -382,7 +382,7 @@ tlso_ctx_init( struct ldapoptions *lo, struct ldaptls 
 		SSL_CTX_set_options( ctx, SSL_OP_NO_SSLv2 );
 
 	if ( lo->ldo_tls_ciphersuite ) {
-#if OPENSSL_VERSION_NUMBER >= 0x10101000
+#if OPENSSL_VERSION_NUMBER >= 0x10101000 && !defined(OPENSSL_NO_TLS1_3)
 		tlso_ctx_cipher13( ctx, lt->lt_ciphersuite );
 #endif /* OpenSSL 1.1.1 */
 		if ( !SSL_CTX_set_cipher_list( ctx, lt->lt_ciphersuite ) )
