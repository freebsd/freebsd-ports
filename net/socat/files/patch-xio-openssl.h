--- xio-openssl.h.orig	2015-01-24 10:15:22 UTC
+++ xio-openssl.h
@@ -21,9 +21,11 @@ extern const struct optdesc opt_openssl_
 extern const struct optdesc opt_openssl_dhparam;
 extern const struct optdesc opt_openssl_cafile;
 extern const struct optdesc opt_openssl_capath;
+#ifdef HAVE_RAND_egd_method
 extern const struct optdesc opt_openssl_egd;
+#endif
 extern const struct optdesc opt_openssl_pseudo;
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
 extern const struct optdesc opt_openssl_compress;
 #endif
 #if WITH_FIPS
