--- libs/tcpd/libcouriertls.c.orig	2015-06-10 00:08:23 UTC
+++ libs/tcpd/libcouriertls.c
@@ -74,7 +74,9 @@ struct proto_ops op_list[] =
     { "TLSv1",     &TLSv1_method,   SSL_OP_ALL },
     { "TLS1",      &TLSv1_method,   SSL_OP_ALL },
     { "SSL3+",     &SSLv23_method,  SSL_OP_ALL|SSL_OP_NO_SSLv2 },
+#ifdef HAVE_SSLV3_METHOD
     { "SSL3",      &SSLv3_method,   SSL_OP_ALL },
+#endif
     { "SSL23",     &SSLv23_method,  SSL_OP_ALL },
     { "",          &SSLv23_method,  SSL_OP_ALL|SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3 },
     { NULL,        &SSLv23_method,  SSL_OP_ALL|SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3 },
