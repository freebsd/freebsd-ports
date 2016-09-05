--- src/tls/tls_rsa.c.orig	2016-01-03 14:49:51 UTC
+++ src/tls/tls_rsa.c
@@ -57,7 +57,7 @@
  /*
   * 2015-12-05: Ephemeral RSA removed from OpenSSL 1.1.0-dev
   */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 /* tls_tmp_rsa_cb - call-back to generate ephemeral RSA key */
 
@@ -109,7 +109,7 @@ int     main(int unused_argc, char *cons
     /*
      * 2015-12-05: Ephemeral RSA removed from OpenSSL 1.1.0-dev
      */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     RSA    *rsa;
 
     msg_vstream_init(argv[0], VSTREAM_ERR);
