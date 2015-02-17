--- xio-openssl.c.orig	2015-01-24 14:33:42 UTC
+++ xio-openssl.c
@@ -108,9 +108,11 @@ const struct optdesc opt_openssl_key    
 const struct optdesc opt_openssl_dhparam     = { "openssl-dhparam",     "dh",    OPT_OPENSSL_DHPARAM,     GROUP_OPENSSL, PH_SPEC, TYPE_FILENAME, OFUNC_SPEC };
 const struct optdesc opt_openssl_cafile      = { "openssl-cafile",     "cafile", OPT_OPENSSL_CAFILE,      GROUP_OPENSSL, PH_SPEC, TYPE_FILENAME, OFUNC_SPEC };
 const struct optdesc opt_openssl_capath      = { "openssl-capath",     "capath", OPT_OPENSSL_CAPATH,      GROUP_OPENSSL, PH_SPEC, TYPE_FILENAME, OFUNC_SPEC };
+#ifdef HAVE_RAND_egd_method
 const struct optdesc opt_openssl_egd         = { "openssl-egd",        "egd",    OPT_OPENSSL_EGD,         GROUP_OPENSSL, PH_SPEC, TYPE_FILENAME, OFUNC_SPEC };
+#endif
 const struct optdesc opt_openssl_pseudo      = { "openssl-pseudo",     "pseudo", OPT_OPENSSL_PSEUDO,      GROUP_OPENSSL, PH_SPEC, TYPE_BOOL,     OFUNC_SPEC };
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
 const struct optdesc opt_openssl_compress    = { "openssl-compress",   "compress", OPT_OPENSSL_COMPRESS,  GROUP_OPENSSL, PH_SPEC, TYPE_STRING,   OFUNC_SPEC };
 #endif
 #if WITH_FIPS
@@ -147,7 +149,7 @@ int xio_reset_fips_mode(void) {
 static void openssl_conn_loginfo(SSL *ssl) {
    Notice1("SSL connection using %s", SSL_get_cipher(ssl));
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
    {
       const COMP_METHOD *comp, *expansion;
 
@@ -651,7 +653,7 @@ int _xioopen_openssl_listen(struct singl
 #endif /* WITH_LISTEN */
 
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
 /* In OpenSSL 0.9.7 compression methods could be added using
  * SSL_COMP_add_compression_method(3), but the implemntation is not compatible
  * with the standard (RFC3749).
@@ -722,8 +724,10 @@ int
    char *opt_dhparam = NULL;	/* file name of DH params */
    char *opt_cafile = NULL;	/* certificate authority file */
    char *opt_capath = NULL;	/* certificate authority directory */
+#ifdef HAVE_RAND_egd_method
    char *opt_egd = NULL;	/* entropy gathering daemon socket path */
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#endif
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
    char *opt_compress = NULL;	/* compression method */
 #endif
    bool opt_pseudo = false;	/* use pseudo entropy if nothing else */
@@ -741,9 +745,11 @@ int
    retropt_string(opts, OPT_OPENSSL_CAPATH, &opt_capath);
    retropt_string(opts, OPT_OPENSSL_KEY, &opt_key);
    retropt_string(opts, OPT_OPENSSL_DHPARAM, &opt_dhparam);
+#ifdef HAVE_RAND_egd_method   
    retropt_string(opts, OPT_OPENSSL_EGD, &opt_egd);
+#endif
    retropt_bool(opts,OPT_OPENSSL_PSEUDO, &opt_pseudo);
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
    retropt_string(opts, OPT_OPENSSL_COMPRESS, &opt_compress);
 #endif
 #if WITH_FIPS
@@ -877,9 +883,11 @@ int
       }
    }
 
+#ifdef HAVE_RAND_egd_method
    if (opt_egd) {
       sycRAND_egd(opt_egd);
    }
+#endif
 
    if (opt_pseudo) {
       long int randdata;
@@ -984,7 +992,7 @@ int
    }
 #endif /* !defined(EC_KEY) */
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
    if (opt_compress) {
       int result;
       result = openssl_setup_compression(*ctx, opt_compress);
@@ -1098,7 +1106,11 @@ static int openssl_SSL_ERROR_SSL(int lev
       if (e == ((ERR_LIB_RAND<<24)|
 		(RAND_F_SSLEAY_RAND_BYTES<<12)|
 		(RAND_R_PRNG_NOT_SEEDED)) /*0x24064064*/) {
+#ifdef HAVE_RAND_egd_method
 	 Error("too few entropy; use options \"egd\" or \"pseudo\"");
+#else
+	 Error("too few entropy; use option \"pseudo\"");
+#endif
 	 stat = STAT_NORETRY;
       } else {
 	 Msg2(level, "%s(): %s", funcname, ERR_error_string(e, buf));
