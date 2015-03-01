--- modules/ssl/ssl_engine_rand.c.orig	2006-07-12 05:38:44.000000000 +0200
+++ modules/ssl/ssl_engine_rand.c	2015-02-28 10:47:35.481607754 +0100
@@ -83,17 +83,6 @@
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
