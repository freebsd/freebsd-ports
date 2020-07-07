--- ssl/swamp/swamp.c.orig	2004-04-30 12:58:00 UTC
+++ ssl/swamp/swamp.c
@@ -105,10 +105,14 @@ static SSL_CTX *ossl_setup_ssl_ctx(const swamp_config 
 	switch(config->sslmeth) {
 	case SWAMP_SSLMETH_NORMAL:
 		sslmethod = SSLv23_client_method(); break;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L && !defined(OPENSSL_NO_SSL2)
 	case SWAMP_SSLMETH_SSLv2:
 		sslmethod = SSLv2_client_method(); break;
+#endif
+#ifndef OPENSSL_NO_SSL3_METHOD
 	case SWAMP_SSLMETH_SSLv3:
 		sslmethod = SSLv3_client_method(); break;
+#endif
 	case SWAMP_SSLMETH_TLSv1:
 		sslmethod = TLSv1_client_method(); break;
 	default:
@@ -151,7 +155,7 @@ static SSL_CTX *ossl_setup_ssl_ctx(const swamp_config 
 		fp = NULL;
 	}
 	if(x509) {
-		if(!X509_STORE_add_cert(ctx->cert_store, x509))
+		if(!X509_STORE_add_cert(SSL_CTX_get_cert_store(ctx), x509))
 			return NULL;
 		/* Reference counts */
 		X509_free(x509);
@@ -444,13 +448,16 @@ possible_reconnect:
 				}
 			}
 			if(ctx->config->output_sessions) {
+				const unsigned char *session_id;
+				unsigned int session_id_length;
 				temp_session = SSL_get1_session(item->ssl);
 				/* debug some stuff :-) */
 				SYS_fprintf(SYS_stderr, "session-id[conn:%i]:", loop);
-				for(tmp = 0; tmp < (int)temp_session->session_id_length;
+				session_id = SSL_SESSION_get_id(temp_session, &session_id_length);
+				for(tmp = 0; tmp < session_id_length;
 						tmp++)
 					SYS_fprintf(SYS_stderr, "%02X",
-						temp_session->session_id[tmp]);
+						session_id[tmp]);
 				SYS_fprintf(SYS_stderr, "\n");
 				SSL_SESSION_free(temp_session);
 			}
