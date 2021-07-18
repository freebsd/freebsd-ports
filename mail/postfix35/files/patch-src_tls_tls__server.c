--- src/tls/tls_server.c.orig	2019-02-18 23:03:54 UTC
+++ src/tls/tls_server.c
@@ -518,7 +518,9 @@ TLS_APPL_STATE *tls_server_init(const TL
 	 * ticket decryption callback already (since 2.11) asks OpenSSL to
 	 * avoid issuing new tickets when the presented ticket is re-usable.
 	 */
+#ifndef LIBRESSL_VERSION_NUMBER
 	SSL_CTX_set_num_tickets(server_ctx, 1);
+#endif
     }
 #endif
     if (!ticketable)
