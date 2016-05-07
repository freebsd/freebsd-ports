--- src/stream.c.orig	2009-07-23 11:16:35 UTC
+++ src/stream.c
@@ -63,11 +63,6 @@ tls_pull (iksparser *prs, char *buffer, 
 static int
 handshake (struct stream_data *data)
 {
-	const int protocol_priority[] = { GNUTLS_TLS1, GNUTLS_SSL3, 0 };
-	const int kx_priority[] = { GNUTLS_KX_RSA, 0 };
-	const int cipher_priority[] = { GNUTLS_CIPHER_3DES_CBC, GNUTLS_CIPHER_ARCFOUR, 0};
-	const int comp_priority[] = { GNUTLS_COMP_ZLIB, GNUTLS_COMP_NULL, 0 };
-	const int mac_priority[] = { GNUTLS_MAC_SHA, GNUTLS_MAC_MD5, 0 };
 	int ret;
 
 	if (gnutls_global_init () != 0)
@@ -80,11 +75,7 @@ handshake (struct stream_data *data)
 		gnutls_certificate_free_credentials (data->cred);
 		return IKS_NOMEM;
 	}
-	gnutls_protocol_set_priority (data->sess, protocol_priority);
-	gnutls_cipher_set_priority(data->sess, cipher_priority);
-	gnutls_compression_set_priority(data->sess, comp_priority);
-	gnutls_kx_set_priority(data->sess, kx_priority);
-	gnutls_mac_set_priority(data->sess, mac_priority);
+	gnutls_set_default_priority(data->sess);
 	gnutls_credentials_set (data->sess, GNUTLS_CRD_CERTIFICATE, data->cred);
 
 	gnutls_transport_set_push_function (data->sess, (gnutls_push_func) tls_push);
