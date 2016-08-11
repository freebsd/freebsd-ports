--- src/network/ssl/ssl.c.orig	2009-08-22 13:15:08.000000000 +0200
+++ src/network/ssl/ssl.c	2015-03-21 12:41:15.886709287 +0100
@@ -49,7 +49,10 @@ init_openssl(struct module *module)
 	 * cannot initialize the PRNG and so every attempt to use SSL fails.
 	 * It's actually an OpenSSL FAQ, and according to them, it's up to the
 	 * application coders to seed the RNG. -- William Yodlowsky */
-	if (RAND_egd(RAND_file_name(f_randfile, sizeof(f_randfile))) < 0) {
+#ifndef OPENSSL_NO_EGD
+	if (RAND_egd(RAND_file_name(f_randfile, sizeof(f_randfile))) < 0) 
+#endif
+	{
 		/* Not an EGD, so read and write to it */
 		if (RAND_load_file(f_randfile, -1))
 			RAND_write_file(f_randfile);
