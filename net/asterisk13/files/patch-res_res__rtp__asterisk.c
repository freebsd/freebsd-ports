$OpenBSD: patch-res_res_rtp_asterisk_c,v 1.1 2016/07/30 21:12:15 sthen Exp $

Obtained from OpenBSD cvs

--- res/res_rtp_asterisk.c.orig	2016-07-21 14:54:02 UTC
+++ res/res_rtp_asterisk.c
@@ -1357,7 +1357,7 @@ static int ast_rtp_dtls_set_configuratio
 		return 0;
 	}
 
-#if OPENSSL_VERSION_NUMBER < 0x10002000L
+#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(LIBRESSL_VERSION_NUMBER)
 	rtp->ssl_ctx = SSL_CTX_new(DTLSv1_method());
 #else
 	rtp->ssl_ctx = SSL_CTX_new(DTLS_method());
