--- apps/dgst.c.orig	Sat Dec 27 15:40:56 2003
+++ apps/dgst.c	Wed Mar 17 13:59:05 2004
@@ -349,7 +349,7 @@
 				{
 				size_t len = strlen(name)+strlen(argv[i])+5;
 				tmp=tofree=OPENSSL_malloc(len);
-				BIO_snprintf(tmp,len,"%s(%s)= ",name,argv[i]);
+				BIO_snprintf(tmp,len,"%s(%s) = ",name,argv[i]);
 				}
 			else
 				tmp="";
