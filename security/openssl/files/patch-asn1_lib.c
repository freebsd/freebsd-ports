--- crypto/asn1/asn1_lib.c.orig	Tue Jul 30 12:18:29 2002
+++ crypto/asn1/asn1_lib.c	Mon Aug  5 18:25:17 2002
@@ -124,7 +124,7 @@
 		(int)(omax+ *pp));
 
 #endif
-	if (*plength > (omax - (*pp - p)))
+	if (*plength > (omax - (p - *pp)))
 		{
 		ASN1err(ASN1_F_ASN1_GET_OBJECT,ASN1_R_TOO_LONG);
 		/* Set this so that even if things are not long enough
