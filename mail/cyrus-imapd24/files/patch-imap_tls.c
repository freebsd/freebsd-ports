$OpenBSD: patch-imap_tls_c,v 1.2 2017/05/28 15:46:11 ajacoutot Exp $
Index: imap/tls.c
--- imap/tls.c.orig	2017-05-15 05:43:30 UTC
+++ imap/tls.c
@@ -225,7 +225,7 @@ static RSA *tmp_rsa_cb(SSL * s __attribute__((unused))
 }
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* replacements for new 1.1 API accessors */
 /* XXX probably put these somewhere central */
 static int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
