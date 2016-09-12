--- ../lion/tls.c.orig	2005-02-17 03:34:13.000000000 +0100
+++ ../lion/tls.c	2016-04-13 21:52:15.409533000 +0200
@@ -94,6 +94,7 @@ int tls_init( void )
 	
 	if (RAND_status() != 1) {
 
+#ifndef OPENSSL_NO_EGD
 		if ( (egdbytes = RAND_egd(ssl_egdsocket)) == -1 ) {
 
 			net_server_SSL = 0;
@@ -105,6 +106,7 @@ int tls_init( void )
 
 			return -2;
 		}
+#endif
 		
 		if (RAND_status() != 1) {
 
