From 9900c16beb14eb3bfc8f4d8c6191e6e1a271c861 Mon Sep 17 00:00:00 2001
From: beck <>
Date: Fri, 4 Dec 2015 04:19:25 +0000
Subject: [PATCH] Fix for OpenSSL CVE-2015-3195 ok djm@ jsing@

---
 src/lib/libssl/src/crypto/asn1/tasn_dec.c | 11 ++++++++---
 1 file changed, 8 insertions(+), 3 deletions(-)

diff --git a/src/lib/libssl/src/crypto/asn1/tasn_dec.c b/src/lib/libssl/src/crypto/asn1/tasn_dec.c
index e50ec0a..0a6eaf2 100644
--- crypto/asn1/tasn_dec.c
+++ crypto/asn1/tasn_dec.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: tasn_dec.c,v 1.26 2015/03/19 14:00:22 tedu Exp $ */
+/* $OpenBSD: tasn_dec.c,v 1.27 2015/07/20 15:41:48 miod Exp $ */
 /* Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL
  * project 2000.
  */
@@ -166,6 +166,10 @@ ASN1_item_ex_d2i(ASN1_VALUE **pval, const unsigned char **in, long len,
 	int otag;
 	int ret = 0;
 	ASN1_VALUE **pchptr;
+	int combine;
+
+	combine = aclass & ASN1_TFLG_COMBINE;
+	aclass &= ~ASN1_TFLG_COMBINE;
 
 	if (!pval)
 		return 0;
@@ -447,7 +451,8 @@ ASN1_item_ex_d2i(ASN1_VALUE **pval, const unsigned char **in, long len,
 auxerr:
 	ASN1err(ASN1_F_ASN1_ITEM_EX_D2I, ASN1_R_AUX_ERROR);
 err:
-	ASN1_item_ex_free(pval, it);
+	if (combine == 0)
+		ASN1_item_ex_free(pval, it);
 	if (errtt)
 		ERR_asprintf_error_data("Field=%s, Type=%s", errtt->field_name,
 		    it->sname);
@@ -642,7 +647,7 @@ asn1_template_noexp_d2i(ASN1_VALUE **val, const unsigned char **in, long len,
 	} else {
 		/* Nothing special */
 		ret = ASN1_item_ex_d2i(val, &p, len, ASN1_ITEM_ptr(tt->item),
-		    -1, 0, opt, ctx);
+		    -1, tt->flags & ASN1_TFLG_COMBINE, opt, ctx);
 		if (!ret) {
 			ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I,
 			    ERR_R_NESTED_ASN1_ERROR);
