--- ./lib/x509rev.cpp.orig	2007-08-13 21:55:50.000000000 +0300
+++ ./lib/x509rev.cpp	2008-06-08 18:23:04.749150142 +0300
@@ -13,8 +13,8 @@
 
 #else
 #define X509_REVOKED_dup(x5r) (X509_REVOKED *)ASN1_dup( \
-	(int (*)(...))i2d_X509_REVOKED, \
-	(char *(*)(...))d2i_X509_REVOKED, \
+	(int (*)())i2d_X509_REVOKED, \
+	(char *(*)())d2i_X509_REVOKED, \
 	(char *)x5r)
 #endif
 
