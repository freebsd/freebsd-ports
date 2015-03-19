--- crypto/pkcs7/pk7_lib.c.orig	2014-12-06 23:15:50 UTC
+++ crypto/pkcs7/pk7_lib.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: pk7_lib.c,v 1.13 2014/07/11 08:44:49 jsing Exp $ */
+/* $OpenBSD: pk7_lib.c,v 1.14 2014/07/12 16:03:37 miod Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -460,6 +460,8 @@ PKCS7_set_digest(PKCS7 *p7, const EVP_MD
 STACK_OF(PKCS7_SIGNER_INFO) *
 PKCS7_get_signer_info(PKCS7 *p7)
 {
+	if (p7 == NULL || p7->d.ptr == NULL)
+		return (NULL);
 	if (PKCS7_type_is_signed(p7)) {
 		return (p7->d.sign->signer_info);
 	} else if (PKCS7_type_is_signedAndEnveloped(p7)) {
