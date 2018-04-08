--- imap/tls.c.orig	2017-08-18 00:29:14 UTC
+++ imap/tls.c
@@ -225,7 +225,7 @@ static RSA *tmp_rsa_cb(SSL * s __attribu
 }
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 /* replacements for new 1.1 API accessors */
 /* XXX probably put these somewhere central */
 static int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
