--- https.c.orig	2008-06-07 07:41:41 UTC
+++ https.c
@@ -15,7 +15,10 @@ SSL *getSSL(void)
 	char f_randfile[PATH_MAX];
 
 	if (!context) {
-		if (RAND_egd(RAND_file_name(f_randfile, sizeof(f_randfile)))<0){
+#ifndef OPENSSL_NO_EGD
+		if (RAND_egd(RAND_file_name(f_randfile, sizeof(f_randfile)))<0)
+#endif
+		{
 			/* Not an EGD, so read and write to it */
 			if (RAND_load_file(f_randfile, -1))
 			       RAND_write_file(f_randfile);
