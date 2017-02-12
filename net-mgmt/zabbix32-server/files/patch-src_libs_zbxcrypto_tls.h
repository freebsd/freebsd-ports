--- src/libs/zbxcrypto/tls.h.orig	2016-12-21 08:08:40 UTC
+++ src/libs/zbxcrypto/tls.h
@@ -60,11 +60,13 @@ typedef struct
 	gnutls_priority_t			ciphersuites_psk;
 #elif defined(HAVE_OPENSSL)
 	SSL_CTX			*ctx_cert;
+#ifndef OPENSSL_NO_PSK
 	SSL_CTX			*ctx_psk;
 	char			*psk_identity_for_cb;
 	size_t			psk_identity_len_for_cb;
 	char			*psk_for_cb;
 	size_t			psk_len_for_cb;
+#endif /* OPENSSL_NO_PSKOPENSSL_NO_PSK */
 #endif
 }
 ZBX_THREAD_SENDVAL_TLS_ARGS;
