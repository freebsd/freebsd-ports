--- src/tls/tls_server.c.orig	2020-07-25 23:49:16 UTC
+++ src/tls/tls_server.c
@@ -502,7 +502,9 @@ TLS_APPL_STATE *tls_server_init(const TLS_SERVER_INIT_
 	 * ticket decryption callback already (since 2.11) asks OpenSSL to
 	 * avoid issuing new tickets when the presented ticket is re-usable.
 	 */
+#ifndef LIBRESSL_VERSION_NUMBER
 	SSL_CTX_set_num_tickets(server_ctx, 1);
+#endif
     }
 #endif
     if (!ticketable)
