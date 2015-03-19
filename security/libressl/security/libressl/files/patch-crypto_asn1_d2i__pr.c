--- crypto/asn1/d2i_pr.c.orig	2015-02-11 14:17:41 UTC
+++ crypto/asn1/d2i_pr.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: d2i_pr.c,v 1.12 2014/07/11 08:44:47 jsing Exp $ */
+/* $OpenBSD: d2i_pr.c,v 1.13 2015/02/11 03:19:37 doug Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -118,7 +118,7 @@ d2i_PrivateKey(int type, EVP_PKEY **a, c
 	return (ret);
 
 err:
-	if ((ret != NULL) && ((a == NULL) || (*a != ret)))
+	if (a == NULL || *a != ret)
 		EVP_PKEY_free(ret);
 	return (NULL);
 }
