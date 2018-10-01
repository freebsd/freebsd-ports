--- src/ssl/bio.cc.orig	2018-06-21 15:26:17 UTC
+++ src/ssl/bio.cc
@@ -76,7 +76,11 @@ Ssl::Bio::Create(const int fd, Security:
         BIO_meth_set_create(SquidMethods, squid_bio_create);
         BIO_meth_set_destroy(SquidMethods, squid_bio_destroy);
     }
+#if defined(LIBRESSL_VERSION_NUMBER)
+    BIO_METHOD *useMethod = SquidMethods;
+#elif !defined(LIBRESSL_VERSION_NUMBER)
     const BIO_METHOD *useMethod = SquidMethods;
+#endif
 #else
     BIO_METHOD *useMethod = &SquidMethods;
 #endif
