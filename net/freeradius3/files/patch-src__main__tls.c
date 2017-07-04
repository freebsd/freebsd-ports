$OpenBSD: patch-src_main_tls_c,v 1.2 2017/05/30 13:12:30 sthen Exp $
Index: src/main/tls.c
--- src/main/tls.c.orig	2017-05-26 18:11:20 UTC
+++ src/main/tls.c
@@ -2031,7 +2031,7 @@ int cbtls_verify(int ok, X509_STORE_CTX 
 	char		cn_str[1024];
 	char		buf[64];
 	X509		*client_cert;
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	const STACK_OF(X509_EXTENSION) *ext_list;
 #else
 	STACK_OF(X509_EXTENSION) *ext_list;
@@ -3038,6 +3038,7 @@ post_ca:
 		SSL_CTX_set_verify_depth(ctx, conf->verify_depth);
 	}
 
+#ifndef LIBRESSL_VERSION_NUMBER
 	/* Load randomness */
 	if (conf->random_file) {
 		if (!(RAND_load_file(conf->random_file, 1024*10))) {
@@ -3045,6 +3046,7 @@ post_ca:
 			return NULL;
 		}
 	}
+#endif
 
 	/*
 	 * Set the cipher list if we were told to
@@ -3166,6 +3168,7 @@ fr_tls_server_conf_t *tls_server_conf_pa
 	 *	Only check for certificate things if we don't have a
 	 *	PSK query.
 	 */
+#ifdef PSK_MAX_IDENTITY_LEN
 	if (conf->psk_identity) {
 		if (conf->private_key_file) {
 			WARN(LOG_PREFIX ": Ignoring private key file due to psk_identity being used");
@@ -3175,7 +3178,9 @@ fr_tls_server_conf_t *tls_server_conf_pa
 			WARN(LOG_PREFIX ": Ignoring certificate file due to psk_identity being used");
 		}
 
-	} else {
+	} else
+#endif
+	{
 		if (!conf->private_key_file) {
 			ERROR(LOG_PREFIX ": TLS Server requires a private key file");
 			goto error;
