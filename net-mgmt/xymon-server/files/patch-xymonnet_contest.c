--- xymonnet/contest.c.orig	2015-03-13 03:28:00.000000000 +0100
+++ xymonnet/contest.c	2015-10-04 15:41:29.655400971 +0200
@@ -480,8 +480,10 @@ static void setup_ssl(tcptest_t *item)
 		  case SSLVERSION_V2:
 			item->sslctx = SSL_CTX_new(SSLv2_client_method()); break;
 #endif
+#ifndef OPENSSL_NO_SSL3
 		  case SSLVERSION_V3:
 			item->sslctx = SSL_CTX_new(SSLv3_client_method()); break;
+#endif
 		  case SSLVERSION_TLS1:
 			item->sslctx = SSL_CTX_new(TLSv1_client_method()); break;
 		  default:
