--- src/ssl.c.orig	2015-03-25 13:10:58 UTC
+++ src/ssl.c
@@ -172,7 +172,7 @@ NOEXPORT int prng_init(GLOBAL_OPTIONS *g
         return 0; /* success */
     }
     s_log(LOG_DEBUG, "RAND_screen failed to sufficiently seed PRNG");
-#else
+#elif !defined(OPENSSL_NO_EGD)
     if(global->egd_sock) {
         if((bytes=RAND_egd(global->egd_sock))==-1) {
             s_log(LOG_WARNING, "EGD Socket %s failed", global->egd_sock);
@@ -185,6 +185,7 @@ NOEXPORT int prng_init(GLOBAL_OPTIONS *g
                          so no need to check if seeded sufficiently */
         }
     }
+#else
     /* try the good-old default /dev/urandom, if available  */
     totbytes+=add_rand_file(global, "/dev/urandom");
     if(RAND_status())
