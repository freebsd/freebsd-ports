$OpenBSD: patch-src_ssl_sock_c,v 1.2 2015/08/25 17:51:52 jca Exp $

Committed upstream

  https://github.com/haproxy/haproxy/commit/17c3f6284cf605e47f6525c077bc644c45272849

--- src/ssl_sock.c.orig	Sat Jul 18 09:40:46 2015
+++ src/ssl_sock.c	Sat Jul 18 09:42:45 2015
@@ -1405,8 +1405,10 @@ int ssl_sock_prepare_ctx(struct bind_conf *bind_conf, 
 		ssloptions |= SSL_OP_NO_TLSv1_2;
 	if (bind_conf->ssl_options & BC_SSL_O_NO_TLS_TICKETS)
 		ssloptions |= SSL_OP_NO_TICKET;
+#ifndef OPENSSL_NO_SSL3
 	if (bind_conf->ssl_options & BC_SSL_O_USE_SSLV3)
 		SSL_CTX_set_ssl_version(ctx, SSLv3_server_method());
+#endif
 	if (bind_conf->ssl_options & BC_SSL_O_USE_TLSV10)
 		SSL_CTX_set_ssl_version(ctx, TLSv1_server_method());
 #if SSL_OP_NO_TLSv1_1
@@ -1750,8 +1752,10 @@ int ssl_sock_prepare_srv_ctx(struct server *srv, struc
 		options |= SSL_OP_NO_TLSv1_2;
 	if (srv->ssl_ctx.options & SRV_SSL_O_NO_TLS_TICKETS)
 		options |= SSL_OP_NO_TICKET;
+#ifndef OPENSSL_NO_SSL3
 	if (srv->ssl_ctx.options & SRV_SSL_O_USE_SSLV3)
 		SSL_CTX_set_ssl_version(srv->ssl_ctx.ctx, SSLv3_client_method());
+#endif
 	if (srv->ssl_ctx.options & SRV_SSL_O_USE_TLSV10)
 		SSL_CTX_set_ssl_version(srv->ssl_ctx.ctx, TLSv1_client_method());
 #if SSL_OP_NO_TLSv1_1
