--- apps/dgst.c.orig	Thu Aug  5 20:10:46 2004
+++ apps/dgst.c	Tue Oct 26 07:02:30 2004
@@ -363,7 +363,7 @@
 				{
 				size_t len = strlen(name)+strlen(argv[i])+(hmac_key ? 5 : 0)+5;
 				tmp=tofree=OPENSSL_malloc(len);
-				BIO_snprintf(tmp,len,"%s%s(%s)= ",
+				BIO_snprintf(tmp,len,"%s%s(%s) = ",
 							 hmac_key ? "HMAC-" : "",name,argv[i]);
 				}
 			else
