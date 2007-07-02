--- ./src/racoon/eaytest.c.orig	Wed Jun  6 01:07:11 2007
+++ ./src/racoon/eaytest.c	Wed Jun  6 01:07:22 2007
@@ -311,7 +311,7 @@
 
 	printf("exact match: succeed.\n");
 
-	if (dnstr_w1) {
+	if (dnstr_w1 != NULL) {
 		asn1dn = eay_str2asn1dn(dnstr_w1, strlen(dnstr_w1));
 		if (asn1dn == NULL || asn1dn->l == asn1dn0.l)
 			errx(1, "asn1dn length wrong for wildcard 1\n");
@@ -321,7 +321,7 @@
 		printf("wildcard 1 match: succeed.\n");
 	}
 
-	if (dnstr_w1) {
+	if (dnstr_w1 != NULL) {
 		asn1dn = eay_str2asn1dn(dnstr_w2, strlen(dnstr_w2));
 		if (asn1dn == NULL || asn1dn->l == asn1dn0.l)
 			errx(1, "asn1dn length wrong for wildcard 2\n");
