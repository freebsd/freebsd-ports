--- src/main.c.orig	2010-07-26 09:21:19.000000000 +0200
+++ src/main.c	2015-02-23 14:54:36.605219022 +0100
@@ -471,8 +471,8 @@
 	    /* Set up OpenSSL thread protection */
 	    ssl_thread_setup(fn);
 	    
-            /* Need to seed PRNG, too! */
-            if ( RAND_egd( ( RAND_file_name( f_randfile, sizeof( f_randfile ) ) == f_randfile ) ? f_randfile : "/.rnd" ) ) 
+            /* Need to seed PRNG, too! 
+            if ( RAND_egd( ( RAND_file_name( f_randfile, sizeof( f_randfile ) ) == f_randfile ) ? f_randfile : "/.rnd" ) ) */
 	    {
                 /* Not an EGD, so read and write it. */
                 if ( RAND_load_file( f_randfile, -1 ) )
