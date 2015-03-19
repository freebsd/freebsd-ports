--- crypto/asn1/n_pkey.c.orig	2015-02-11 14:17:41 UTC
+++ crypto/asn1/n_pkey.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: n_pkey.c,v 1.24 2015/02/11 03:39:51 jsing Exp $ */
+/* $OpenBSD: n_pkey.c,v 1.25 2015/02/11 04:00:39 jsing Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -340,11 +340,11 @@ d2i_RSA_NET(RSA **a, const unsigned char
 		return NULL;
 	}
 
-	if ((enckey->os->length != 11) || (strncmp("private-key",
-	(char *)enckey->os->data, 11) != 0)) {
+	/* XXX 11 == strlen("private-key") */
+	if (enckey->os->length != 11 ||
+	    memcmp("private-key", enckey->os->data, 11) != 0) {
 		ASN1err(ASN1_F_D2I_RSA_NET, ASN1_R_PRIVATE_KEY_HEADER_MISSING);
-		NETSCAPE_ENCRYPTED_PKEY_free(enckey);
-		return NULL;
+		goto err;
 	}
 	if (OBJ_obj2nid(enckey->enckey->algor->algorithm) != NID_rc4) {
 		ASN1err(ASN1_F_D2I_RSA_NET,
