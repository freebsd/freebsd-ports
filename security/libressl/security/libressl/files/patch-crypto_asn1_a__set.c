--- crypto/asn1/a_set.c.orig	2014-12-06 23:15:50 UTC
+++ crypto/asn1/a_set.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: a_set.c,v 1.15 2014/07/10 13:58:22 jsing Exp $ */
+/* $OpenBSD: a_set.c,v 1.16 2014/07/11 08:44:47 jsing Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -225,7 +225,7 @@ d2i_ASN1_SET(STACK_OF(OPENSSL_BLOCK) **a
 	return ret;
 
 err:
-	if (ret != NULL && (a == NULL || *a != ret)) {
+	if (a == NULL || *a != ret) {
 		if (free_func != NULL)
 			sk_OPENSSL_BLOCK_pop_free(ret, free_func);
 		else
