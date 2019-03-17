--- libs/libpkixipext/pkixip_ext_gram.y.orig	2019-02-27 16:25:45 UTC
+++ libs/libpkixipext/pkixip_ext_gram.y
@@ -350,7 +350,7 @@ new_aor(void)
 
 	if (!ipc->u.addressesOrRanges &&
 	    !(ipc->u.addressesOrRanges =
-	      sk_new(pkixip_aor_cmp))) {
+	      sk_IPAddressOrRange_new(pkixip_aor_cmp))) {
 		applog(LOG_CRIT, "no memory");
 		return (-1);
 	}
@@ -361,7 +361,7 @@ new_aor(void)
 		applog(LOG_CRIT, "%s: no memory", __FUNCTION__);
 		return (-1);
 	}
-	if (!sk_push(ipc->u.addressesOrRanges, (char *)aor)) {
+	if (!sk_IPAddressOrRange_push(ipc->u.addressesOrRanges, (char *)aor)) {
 		applog(LOG_CRIT, "sk_push() failed");
 		return (-1);
 	}
@@ -459,8 +459,8 @@ af_already_exists(void)
 	int i;
 	IPAddressFamily *e_ipf;
 
-	for (i = 0; i < sk_num(parse_ipb); i++) {
-		e_ipf = (IPAddressFamily *)sk_value(parse_ipb, i);
+	for (i = 0; i < sk_IPAddressFamily_num(parse_ipb); i++) {
+		e_ipf = sk_IPAddressFamily_value(parse_ipb, i);
 		if (af_match(ipf, e_ipf)) {
 			return (1);
 		}
