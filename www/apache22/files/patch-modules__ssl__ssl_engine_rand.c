--- modules/ssl/ssl_engine_rand.c.orig	2006-07-12 03:38:44 UTC
+++ modules/ssl/ssl_engine_rand.c
@@ -83,17 +83,6 @@ int ssl_rand_seed(server_rec *s, apr_poo
                 nDone += ssl_rand_feedfp(p, fp, pRandSeed->nBytes);
                 ssl_util_ppclose(s, p, fp);
             }
-#ifdef HAVE_SSL_RAND_EGD
-            else if (pRandSeed->nSrc == SSL_RSSRC_EGD) {
-                /*
-                 * seed in contents provided by the external
-                 * Entropy Gathering Daemon (EGD)
-                 */
-                if ((n = RAND_egd(pRandSeed->cpPath)) == -1)
-                    continue;
-                nDone += n;
-            }
-#endif
             else if (pRandSeed->nSrc == SSL_RSSRC_BUILTIN) {
                 struct {
                     time_t t;
