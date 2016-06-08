$OpenBSD: patch-opts_c,v 1.3 2015/08/28 11:05:22 jca Exp $

Fixed upstream

  https://github.com/droe/sslsplit/commit/57a2ab85884e8bacec8b03aa5a3f935376f43a2d

--- opts.c.orig	Mon Mar 16 00:24:02 2015
+++ opts.c	Fri Aug 28 12:34:18 2015
@@ -143,7 +143,7 @@ opts_proto_force(opts_t *opts, const char *optarg, con
 		opts->sslmethod = SSLv2_method;
 	} else
 #endif /* SSL_OP_NO_SSLv2 && WITH_SSLV2 */
-#ifdef SSL_OP_NO_SSLv3
+#if defined(SSL_OP_NO_SSLv3) && !defined(OPENSSL_NO_SSL3_METHOD)
 	if (!strcmp(optarg, "ssl3")) {
 		opts->sslmethod = SSLv3_method;
 	} else
@@ -219,7 +219,7 @@ opts_proto_dbg_dump(opts_t *opts)
 #if defined(SSL_OP_NO_SSLv2) && defined(WITH_SSLV2)
 	               (opts->sslmethod == SSLv2_method) ? "nossl2" :
 #endif /* SSL_OP_NO_SSLv2 && WITH_SSLV2 */
-#ifdef SSL_OP_NO_SSLv3
+#if defined(SSL_OP_NO_SSLv3) && !defined(OPENSSL_NO_SSL3_METHOD)
 	               (opts->sslmethod == SSLv3_method) ? "ssl3" :
 #endif /* SSL_OP_NO_SSLv3 */
 #ifdef SSL_OP_NO_TLSv1
