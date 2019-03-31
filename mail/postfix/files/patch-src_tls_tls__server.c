--- src/tls/tls_server.c.orig	2018-11-17 22:33:15 UTC
+++ src/tls/tls_server.c
@@ -517,7 +517,9 @@ TLS_APPL_STATE *tls_server_init(const TL
 	 * ticket decryption callback already (since 2.11) asks OpenSSL to
 	 * avoid issuing new tickets when the presented ticket is re-usable.
 	 */
+#ifndef LIBRESSL_VERSION_NUMBER
 	SSL_CTX_set_num_tickets(server_ctx, 1);
+#endif
     }
 #endif
     if (!ticketable)
