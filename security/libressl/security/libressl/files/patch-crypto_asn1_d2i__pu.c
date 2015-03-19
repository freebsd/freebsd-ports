--- crypto/asn1/d2i_pu.c.orig	2014-12-06 23:15:50 UTC
+++ crypto/asn1/d2i_pu.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: d2i_pu.c,v 1.11 2014/07/10 22:45:56 jsing Exp $ */
+/* $OpenBSD: d2i_pu.c,v 1.12 2014/07/11 08:44:47 jsing Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -130,7 +130,7 @@ d2i_PublicKey(int type, EVP_PKEY **a, co
 	return (ret);
 
 err:
-	if ((ret != NULL) && ((a == NULL) || (*a != ret)))
+	if (a == NULL || *a != ret)
 		EVP_PKEY_free(ret);
 	return (NULL);
 }
