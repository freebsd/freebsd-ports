--- libraries/libldap/tls_o.c.orig	2024-01-29 18:52:23 UTC
+++ libraries/libldap/tls_o.c
@@ -281,7 +281,7 @@ tlso_ctx_free ( tls_ctx *ctx )
 	SSL_CTX_free( c );
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000
+#if OPENSSL_VERSION_NUMBER >= 0x10101000 && !defined(OPENSSL_NO_TLS1_3)
 static char *
 tlso_stecpy( char *dst, const char *src, const char *end )
 {
@@ -427,7 +427,7 @@ tlso_ctx_init( struct ldapoptions *lo, struct ldaptls 
 
 	if ( lo->ldo_tls_ciphersuite ) {
 		char *oldsuites = lt->lt_ciphersuite;
-#if OPENSSL_VERSION_NUMBER >= 0x10101000
+#if OPENSSL_VERSION_NUMBER >= 0x10101000 && !defined(OPENSSL_NO_TLS1_3)
 		tlso_ctx_cipher13( ctx, lt->lt_ciphersuite, &oldsuites );
 #endif
 		if ( oldsuites && !SSL_CTX_set_cipher_list( ctx, oldsuites ) )
