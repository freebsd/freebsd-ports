# libressl support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=196139
# https://issues.apache.org/bugzilla/show_bug.cgi?id=57375

--- modules/ssl/ssl_engine_rand.c.orig	2011-12-05 00:08:01 UTC
+++ modules/ssl/ssl_engine_rand.c
@@ -81,6 +81,7 @@ int ssl_rand_seed(server_rec *s, apr_poo
                 nDone += ssl_rand_feedfp(p, fp, pRandSeed->nBytes);
                 ssl_util_ppclose(s, p, fp);
             }
+#ifdef HAVE_RAND_EGD
             else if (pRandSeed->nSrc == SSL_RSSRC_EGD) {
                 /*
                  * seed in contents provided by the external
@@ -90,6 +91,7 @@ int ssl_rand_seed(server_rec *s, apr_poo
                     continue;
                 nDone += n;
             }
+#endif
             else if (pRandSeed->nSrc == SSL_RSSRC_BUILTIN) {
                 struct {
                     time_t t;
