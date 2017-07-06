--- modules/ssl/ssl_util_stapling.c.orig	2017-07-06 21:11:28 UTC
+++ modules/ssl/ssl_util_stapling.c
@@ -91,7 +91,7 @@ static X509 *stapling_get_issuer(modssl_
     for (i = 0; i < sk_X509_num(extra_certs); i++) {
         issuer = sk_X509_value(extra_certs, i);
         if (X509_check_issued(issuer, x) == X509_V_OK) {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || LIBRESSL_VERSION_NUMBER < 0x2050000fL
             CRYPTO_add(&issuer->references, 1, CRYPTO_LOCK_X509);
 #else
             X509_up_ref(issuer);
