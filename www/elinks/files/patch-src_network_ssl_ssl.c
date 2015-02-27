--- src/network/ssl/ssl.c.orig	2009-08-22 13:15:08.000000000 +0200
+++ src/network/ssl/ssl.c	2015-02-27 21:53:29.478028717 +0100
@@ -49,11 +49,9 @@
 	 * cannot initialize the PRNG and so every attempt to use SSL fails.
 	 * It's actually an OpenSSL FAQ, and according to them, it's up to the
 	 * application coders to seed the RNG. -- William Yodlowsky */
-	if (RAND_egd(RAND_file_name(f_randfile, sizeof(f_randfile))) < 0) {
-		/* Not an EGD, so read and write to it */
-		if (RAND_load_file(f_randfile, -1))
-			RAND_write_file(f_randfile);
-	}
+	/* Not an EGD, so read and write to it */
+	if (RAND_load_file(f_randfile, -1))
+		RAND_write_file(f_randfile);
 
 	SSLeay_add_ssl_algorithms();
 	context = SSL_CTX_new(SSLv23_client_method());
