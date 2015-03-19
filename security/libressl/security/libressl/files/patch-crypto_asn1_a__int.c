--- crypto/asn1/a_int.c.orig	2015-02-10 14:54:46 UTC
+++ crypto/asn1/a_int.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: a_int.c,v 1.24 2014/07/11 08:44:47 jsing Exp $ */
+/* $OpenBSD: a_int.c,v 1.25 2015/02/10 08:33:10 jsing Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -268,7 +268,7 @@ c2i_ASN1_INTEGER(ASN1_INTEGER **a, const
 
 err:
 	ASN1err(ASN1_F_C2I_ASN1_INTEGER, i);
-	if ((ret != NULL) && ((a == NULL) || (*a != ret)))
+	if (a == NULL || *a != ret)
 		M_ASN1_INTEGER_free(ret);
 	return (NULL);
 }
@@ -335,7 +335,7 @@ d2i_ASN1_UINTEGER(ASN1_INTEGER **a, cons
 
 err:
 	ASN1err(ASN1_F_D2I_ASN1_UINTEGER, i);
-	if ((ret != NULL) && ((a == NULL) || (*a != ret)))
+	if (a == NULL || *a != ret)
 		M_ASN1_INTEGER_free(ret);
 	return (NULL);
 }
