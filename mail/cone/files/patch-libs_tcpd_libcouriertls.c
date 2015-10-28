--- libs/tcpd/libcouriertls.c.orig	2014-10-22 08:00:04 UTC
+++ libs/tcpd/libcouriertls.c
@@ -74,7 +74,15 @@ struct proto_ops op_list[] =
     { "TLSv1",     &TLSv1_method,   SSL_OP_ALL },
     { "TLS1",      &TLSv1_method,   SSL_OP_ALL },
     { "SSL3+",     &SSLv23_method,  SSL_OP_ALL|SSL_OP_NO_SSLv2 },
+#ifndef OPENSSL_NO_SSL3
     { "SSL3",      &SSLv3_method,   SSL_OP_ALL },
+#else
+    { "SSL3",      &SSLv23_method,   SSL_OP_ALL|SSL_OP_NO_SSLv2|SSL_OP_NO_TLSv1 
+#ifdef HAVE_TLSV1_1_METHOD
+      |SSL_OP_NO_TLSv1_1|SSL_OP_NO_TLSv1_2
+#endif /* SSL_OP_NO_TLSv1 */
+    },
+#endif /* OPENSSL_NO_SSL3 */
     { "SSL23",     &SSLv23_method,  SSL_OP_ALL },
     { "",          &SSLv23_method,  SSL_OP_ALL|SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3 },
     { NULL,        &SSLv23_method,  SSL_OP_ALL|SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3 },
