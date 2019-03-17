--- sendd/cpa.c.orig	2019-02-27 16:25:45 UTC
+++ sendd/cpa.c
@@ -183,22 +183,23 @@ next:
 }
 
 static int
-can_handle_cps(uint8_t *ops, int len, STACK *chain, X509 **x)
+can_handle_cps(uint8_t *ops, int len, STACK_OF(X509_OBJECT) *chain, X509 **x)
 {
 	int i, j, r = 0;
 	X509_NAME *dn;
-	X509 x509_s;
-	X509_CINF cinf_s;
-	STACK *dchain;
+	X509 *x509_s;
+	STACK_OF(X509_OBJECT) *dchain;
 	STACK_OF(X509_NAME) *dns;
 
 	*x = NULL;
-
+	x509_s = X509_new();
+	if (x509_s == NULL)
+		return (1);
 	if ((dns = snd_get_trustanchors_from_opts(ops, len)) == NULL) {
 		return (1);
 	}
-	if (sk_num(dns) == 0) {
-		sk_free(dns);
+	if (sk_X509_NAME_num(dns) == 0) {
+		sk_X509_NAME_free(dns);
 		return (1);
 	}
 
@@ -209,24 +210,22 @@ can_handle_cps(uint8_t *ops, int len, STACK *chain, X5
 	 * sorting (triggered by sk_find), and we need to chain order
 	 * preserved so we can send out the certs in correct order.
 	 */
-	if ((dchain = sk_dup(chain)) == NULL) {
+	if ((dchain = sk_X509_OBJECT_dup(chain)) == NULL) {
 		applog(LOG_CRIT, "%s: no memory", __FUNCTION__);
 		goto done;
 	}
-	x509_s.cert_info= &cinf_s;
-
-	for (i = 0; i < sk_num(dns); i++) {
+	for (i = 0; i < sk_X509_num(dns); i++) {
 		dn = sk_X509_NAME_value(dns, i);
-		cinf_s.subject=dn;
+		X509_set_subject_name(x509_s, dn);
 
-		if ((j = sk_X509_find(dchain, &x509_s)) >= 0) {
+		if ((j = sk_X509_NAME_find(dchain, x509_s)) >= 0) {
 			r = 1;
 			*x = sk_X509_value(dchain, j);
 			DBG(dbg, "found");
 			break;
 		}
 	}
-	sk_free(dchain);
+	sk_X509_OBJECT_free(dchain);
 
 done:
 	sk_X509_NAME_pop_free(dns, X509_NAME_free);
