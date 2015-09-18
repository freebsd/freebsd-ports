--- pjlib/src/pj/ssl_sock_ossl.c.orig	2014-08-22 03:44:29.000000000 +0200
+++ pjlib/src/pj/ssl_sock_ossl.c	2015-09-10 16:33:47.963114013 +0200
@@ -333,8 +333,10 @@ static pj_status_t init_openssl(void)
 	meth = (SSL_METHOD*)SSLv23_server_method();
 	if (!meth)
 	    meth = (SSL_METHOD*)TLSv1_server_method();
+#ifndef OPENSSL_NO_SSL3
 	if (!meth)
 	    meth = (SSL_METHOD*)SSLv3_server_method();
+#endif
 #ifndef OPENSSL_NO_SSL2
 	if (!meth)
 	    meth = (SSL_METHOD*)SSLv2_server_method();
@@ -525,9 +527,11 @@ static pj_status_t create_ssl(pj_ssl_soc
 	ssl_method = (SSL_METHOD*)SSLv2_method();
 	break;
 #endif
+#ifndef OPENSSL_NO_SSL3
     case PJ_SSL_SOCK_PROTO_SSL3:
 	ssl_method = (SSL_METHOD*)SSLv3_method();
 	break;
+#endif
     case PJ_SSL_SOCK_PROTO_DEFAULT:
     case PJ_SSL_SOCK_PROTO_SSL23:
 	ssl_method = (SSL_METHOD*)SSLv23_method();
