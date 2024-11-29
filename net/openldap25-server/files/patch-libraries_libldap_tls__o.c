--- libraries/libldap/tls_o.c.orig	2024-11-26 17:12:48 UTC
+++ libraries/libldap/tls_o.c
@@ -286,7 +286,7 @@ tlso_ctx_free ( tls_ctx *ctx )
 	SSL_CTX_free( c );
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000
+#if OPENSSL_VERSION_NUMBER >= 0x10101000 && !defined(OPENSSL_NO_TLS1_3)
 static char *
 tlso_stecpy( char *dst, const char *src, const char *end )
 {
@@ -433,7 +433,7 @@ tlso_ctx_init( struct ldapoptions *lo, struct ldaptls 
 
 	if ( lo->ldo_tls_ciphersuite ) {
 		char *oldsuites = lt->lt_ciphersuite;
-#if OPENSSL_VERSION_NUMBER >= 0x10101000
+#if OPENSSL_VERSION_NUMBER >= 0x10101000 && !defined(OPENSSL_NO_TLS1_3)
 		if ( tlso_ctx_cipher13( ctx, lt->lt_ciphersuite, &oldsuites ))
 		{
 			Debug1( LDAP_DEBUG_ANY,
