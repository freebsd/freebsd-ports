--- lib/isasu.c.orig	Wed Feb 20 02:40:06 2002
+++ lib/isasu.c	Thu May 19 16:23:01 2005
@@ -12,6 +12,7 @@
 #include <init.h>
 #include <unistd.h>
 #include <fcntl.h>
+#include <openscep_err.h>
 
 /*
  * the methods in this file are based on the similar functions for the
@@ -40,7 +41,7 @@
 	M_ASN1_D2I_get(ret->issuer, d2i_X509_NAME);
 	M_ASN1_D2I_get(ret->subject, d2i_X509_NAME);
 	M_ASN1_D2I_Finish(a,issuer_and_subject_free,
-		ASN1_F_D2I_PKCS7_ISSUER_AND_SERIAL);
+		OPENSCEP_F_D2I_ISSUER_AND_SUBJECT);
 }
 
 issuer_and_subject_t	*issuer_and_subject_new(void) {
@@ -50,7 +51,7 @@
 	M_ASN1_New(ret->issuer, X509_NAME_new);
 	M_ASN1_New(ret->subject, X509_NAME_new);
 	return ret;
-	M_ASN1_New_Error(ASN1_F_PKCS7_ISSUER_AND_SERIAL_NEW); /* wrong error code */
+	M_ASN1_New_Error(OPENSCEP_F_ISSUER_AND_SUBJECT_NEW);
 }
 
 void	issuer_and_subject_free(issuer_and_subject_t *isasu) {
