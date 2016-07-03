--- src/main.c.orig	2016-01-29 18:11:40 UTC
+++ src/main.c
@@ -473,7 +473,9 @@ int main( int argc, char *argv[] )
 	    ssl_thread_setup(fn);
 	    
             /* Need to seed PRNG, too! */
+#ifndef OPENSSL_NO_EGD
             if ( RAND_egd( ( RAND_file_name( f_randfile, sizeof( f_randfile ) ) == f_randfile ) ? f_randfile : "/.rnd" ) ) 
+#endif
 	    {
                 /* Not an EGD, so read and write it. */
                 if ( RAND_load_file( f_randfile, -1 ) )
