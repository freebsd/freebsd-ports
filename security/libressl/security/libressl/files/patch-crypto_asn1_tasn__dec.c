--- crypto/asn1/tasn_dec.c.orig	2015-02-14 19:09:01 UTC
+++ crypto/asn1/tasn_dec.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: tasn_dec.c,v 1.24 2014/06/12 15:49:27 deraadt Exp $ */
+/* $OpenBSD: tasn_dec.c,v 1.25 2015/02/14 15:23:57 miod Exp $ */
 /* Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL
  * project 2000.
  */
@@ -238,8 +238,16 @@ ASN1_item_ex_d2i(ASN1_VALUE **pval, cons
 		if (asn1_cb && !asn1_cb(ASN1_OP_D2I_PRE, pval, it, NULL))
 			goto auxerr;
 
-		/* Allocate structure */
-		if (!*pval && !ASN1_item_ex_new(pval, it)) {
+		if (*pval) {
+			/* Free up and zero CHOICE value if initialised */
+			i = asn1_get_choice_selector(pval, it);
+			if ((i >= 0) && (i < it->tcount)) {
+				tt = it->templates + i;
+				pchptr = asn1_get_field_ptr(pval, tt);
+				ASN1_template_free(pchptr, tt);
+				asn1_set_choice_selector(pval, -1, it);
+			}
+		} else if (!ASN1_item_ex_new(pval, it)) {
 			ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
 			    ERR_R_NESTED_ASN1_ERROR);
 			goto err;
@@ -325,6 +333,19 @@ ASN1_item_ex_d2i(ASN1_VALUE **pval, cons
 		if (asn1_cb && !asn1_cb(ASN1_OP_D2I_PRE, pval, it, NULL))
 			goto auxerr;
 
+		/* Free up and zero any ADB found */
+		for (i = 0, tt = it->templates; i < it->tcount; i++, tt++) {
+			if (tt->flags & ASN1_TFLG_ADB_MASK) {
+				const ASN1_TEMPLATE *seqtt;
+				ASN1_VALUE **pseqval;
+				seqtt = asn1_do_adb(pval, tt, 1);
+				if (!seqtt)
+					goto err;
+				pseqval = asn1_get_field_ptr(pval, seqtt);
+				ASN1_template_free(pseqval, seqtt);
+			}
+		}
+
 		/* Get each field entry */
 		for (i = 0, tt = it->templates; i < it->tcount; i++, tt++) {
 			const ASN1_TEMPLATE *seqtt;
