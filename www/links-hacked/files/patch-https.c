--- https.c.orig	2008-06-07 09:41:41.000000000 +0200
+++ https.c	2015-02-27 22:32:57.331936616 +0100
@@ -15,11 +15,8 @@
 	char f_randfile[PATH_MAX];
 
 	if (!context) {
-		if (RAND_egd(RAND_file_name(f_randfile, sizeof(f_randfile)))<0){
-			/* Not an EGD, so read and write to it */
-			if (RAND_load_file(f_randfile, -1))
-			       RAND_write_file(f_randfile);
-		}
+		if (RAND_load_file(f_randfile, -1))
+		       RAND_write_file(f_randfile);
 		SSLeay_add_ssl_algorithms();
 		context = SSL_CTX_new(SSLv23_client_method());
 		SSL_CTX_set_options(context, SSL_OP_ALL);
