--- xio-openssl.c.orig	2015-01-24 14:33:42 UTC
+++ xio-openssl.c
@@ -110,7 +110,7 @@ const struct optdesc opt_openssl_cafile 
 const struct optdesc opt_openssl_capath      = { "openssl-capath",     "capath", OPT_OPENSSL_CAPATH,      GROUP_OPENSSL, PH_SPEC, TYPE_FILENAME, OFUNC_SPEC };
 const struct optdesc opt_openssl_egd         = { "openssl-egd",        "egd",    OPT_OPENSSL_EGD,         GROUP_OPENSSL, PH_SPEC, TYPE_FILENAME, OFUNC_SPEC };
 const struct optdesc opt_openssl_pseudo      = { "openssl-pseudo",     "pseudo", OPT_OPENSSL_PSEUDO,      GROUP_OPENSSL, PH_SPEC, TYPE_BOOL,     OFUNC_SPEC };
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
 const struct optdesc opt_openssl_compress    = { "openssl-compress",   "compress", OPT_OPENSSL_COMPRESS,  GROUP_OPENSSL, PH_SPEC, TYPE_STRING,   OFUNC_SPEC };
 #endif
 #if WITH_FIPS
@@ -147,7 +147,7 @@ int xio_reset_fips_mode(void) {
 static void openssl_conn_loginfo(SSL *ssl) {
    Notice1("SSL connection using %s", SSL_get_cipher(ssl));
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
    {
       const COMP_METHOD *comp, *expansion;
 
@@ -878,7 +878,9 @@ int
    }
 
    if (opt_egd) {
+#ifdef HAVE_RAND_EGD
       sycRAND_egd(opt_egd);
+#endif
    }
 
    if (opt_pseudo) {
