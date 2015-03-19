--- crypto/asn1/x_x509.c.orig	2015-02-11 14:17:41 UTC
+++ crypto/asn1/x_x509.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: x_x509.c,v 1.22 2015/02/11 03:39:51 jsing Exp $ */
+/* $OpenBSD: x_x509.c,v 1.23 2015/02/11 04:00:39 jsing Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -313,16 +313,20 @@ d2i_X509_AUX(X509 **a, const unsigned ch
 
 	/* Save start position */
 	q = *pp;
-	ret = d2i_X509(a, pp, length);
+	ret = d2i_X509(NULL, pp, length);
 	/* If certificate unreadable then forget it */
 	if (!ret)
 		return NULL;
 	/* update length */
 	length -= *pp - q;
-	if (!length)
-		return ret;
-	if (!d2i_X509_CERT_AUX(&ret->aux, pp, length))
-		goto err;
+	if (length > 0) {
+		if (!d2i_X509_CERT_AUX(&ret->aux, pp, length))
+			goto err;
+	}
+	if (a != NULL) {
+		X509_free(*a);
+		*a = ret;
+	}
 	return ret;
 
 err:
