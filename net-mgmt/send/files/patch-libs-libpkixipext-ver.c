--- libs/libpkixipext/ver.c.orig	2019-02-27 16:25:45 UTC
+++ libs/libpkixipext/ver.c
@@ -101,11 +101,15 @@ static int
 in_range(ASN1_BIT_STRING *min1, ASN1_BIT_STRING *max1, ASN1_BIT_STRING *min2,
     ASN1_BIT_STRING *max2, int af)
 {
-	BIGNUM bpmin[1], bpmax[1], bmin[1], bmax[1];
-	int alen, len, bits;
+	BIGNUM *bpmin, *bpmax, *bmin, *bmax;
+	int alen, len, bits, ret;
 	uint8_t mask, buf[sizeof (struct in6_addr)];
 
-	BN_init(bpmin); BN_init(bpmax); BN_init(bmin); BN_init(bmax);
+	bpmin = BN_new();
+	bpmax = BN_new();
+	bmin = BN_new();
+	bmax = BN_new();
+	ret = 0;
 	switch (af) {
 	case AF_INET:
 		alen = sizeof (struct in_addr);
@@ -115,14 +119,14 @@ in_range(ASN1_BIT_STRING *min1, ASN1_BIT_STRING *max1,
 		break;
 	default:
 		DBG(&dbg_ver, "Unsupported AF");
-		return (0);
+		goto end;
 	}
 
 	len = min1->length < alen ? min1->length : alen;
 	memset(buf, 0, sizeof (buf));
 	memcpy(buf, min1->data, len);
 	if (!BN_bin2bn(buf, alen, bpmin)) {
-		return (0);
+		goto end;
 	}
 
 	len = max1->length < alen ? max1->length : alen;
@@ -135,14 +139,14 @@ in_range(ASN1_BIT_STRING *min1, ASN1_BIT_STRING *max1,
 		buf[len - 1] |= mask;
 	}
 	if (!BN_bin2bn(buf, alen, bpmax)) {
-		return (0);
+		goto end;
 	}
 
 	len = min2->length < alen ? min2->length : alen;
 	memset(buf, 0, sizeof (buf));
 	memcpy(buf, min2->data, len);
 	if (!BN_bin2bn(buf, alen, bmin)) {
-		return (0);
+		goto end;
 	}
 
 	len = max2->length < alen ? max2->length : alen;
@@ -155,18 +159,24 @@ in_range(ASN1_BIT_STRING *min1, ASN1_BIT_STRING *max1,
 		buf[len - 1] |= mask;
 	}
 	if (!BN_bin2bn(buf, alen, bmax)) {
-		return (0);
+		goto end;
 	}
 
 	/* bmin <= bpmin <= bpmax <= bmax. We already know bpmin <= bpmax */
 	if (BN_cmp(bmin, bpmin) == 1) {
-		return (0);
+		goto end;
 	}
 	if (BN_cmp(bpmax, bmax) == 1) {
-		return (0);
+		goto end;
 	}
+	ret = 1;
+end:
+	BN_free(bpmin);
+	BN_free(bpmax);
+	BN_free(bmin);
+	BN_free(bmax);
 
-	return (1);
+	return (ret);
 }
 
 static int
@@ -247,16 +257,14 @@ af_cmp(IPAddressFamily *ipf1, IPAddressFamily *ipf2)
 	}
 
 	DBG(&dbg_ver, "Pre-cmp ipc AOR count: %d",
-	    sk_num(ipc1->u.addressesOrRanges));
+	    sk_IPAddressOrRange_num(ipc1->u.addressesOrRanges));
 
-	for (i = 0; i < sk_num(ipc1->u.addressesOrRanges); i++) {
-		aor1 =
-		    (IPAddressOrRange *)sk_value(ipc1->u.addressesOrRanges, i);
-		for (j = 0; j < sk_num(ipc2->u.addressesOrRanges); j++) {
-			aor2 = (IPAddressOrRange *)
-			    sk_value(ipc2->u.addressesOrRanges, j);
+	for (i = 0; i < sk_IPAddressOrRange_num(ipc1->u.addressesOrRanges); i++) {
+		aor1 = sk_IPAddressOrRange_value(ipc1->u.addressesOrRanges, i);
+		for (j = 0; j < sk_IPAddressOrRange_num(ipc2->u.addressesOrRanges); j++) {
+			aor2 = sk_IPAddressOrRange_value(ipc2->u.addressesOrRanges, j);
 			if (aor_match(aor1, aor2, af) == 0) {
-				sk_delete(ipc1->u.addressesOrRanges, i--);
+				sk_IPAddressOrRange_delete(ipc1->u.addressesOrRanges, i--);
 				IPAddressOrRange_free(aor1);
 				break;
 			}
@@ -264,9 +272,9 @@ af_cmp(IPAddressFamily *ipf1, IPAddressFamily *ipf2)
 	}
 
 	DBG(&dbg_ver, "Post-cmp ipc AOR count: %d",
-	    sk_num(ipc1->u.addressesOrRanges));
+	    sk_IPAddressOrRange_num(ipc1->u.addressesOrRanges));
 
-	if (sk_num(ipc1->u.addressesOrRanges) == 0) {
+	if (sk_IPAddressOrRange_num(ipc1->u.addressesOrRanges) == 0) {
 		return (0);
 	}
 
@@ -307,7 +315,7 @@ verify_ipext_cert(X509_STORE_CTX *ctx, int idx, X509 *
 	IPAddressFamily *ipf1, *ipf2;
 	int i, j, inherit = 0;
 
-	DBG(&dbg_ver, "vipb stack cnt: %d idx: %d", sk_num(vipb), idx);
+	DBG(&dbg_ver, "vipb stack cnt: %d idx: %d", sk_IPAddressFamily_num(vipb), idx);
 
 	ipb = X509_get_ext_d2i(x, pkix_ip_ext_method.ext_nid, NULL, NULL);
 	if (!ipb) {
@@ -315,18 +323,18 @@ verify_ipext_cert(X509_STORE_CTX *ctx, int idx, X509 *
 		return (-1);
 	}
 
-	for (i = 0; i < sk_num(vipb); i++) {
-		ipf1 = (IPAddressFamily *)sk_value(vipb, i);
+	for (i = 0; i < sk_IPAddressFamily_num(vipb); i++) {
+		ipf1 = sk_IPAddressFamily_value(vipb, i);
 
 		/* Ignore inherits in vipb */
 		if (is_inherit(ipf1)) {
-			sk_delete(vipb, i--);
+			sk_IPAddressFamily_delete(vipb, i--);
 			IPAddressFamily_free(ipf1);
 			continue;
 		}
 
-		for (j = 0; j < sk_num(ipb); j++) {
-			ipf2 = (IPAddressFamily *)sk_value(ipb, j);
+		for (j = 0; j < sk_IPAddressFamily_num(ipb); j++) {
+			ipf2 = sk_IPAddressFamily_value(ipb, j);
 			if (af_match(ipf1, ipf2)) {
 				/*
 				 * Inherits in ipb need to be checked
@@ -338,7 +346,7 @@ verify_ipext_cert(X509_STORE_CTX *ctx, int idx, X509 *
 				}
 
 				if (af_cmp(ipf1, ipf2) == 0) {
-					sk_delete(vipb, i--);
+					sk_IPAddressFamily_delete(vipb, i--);
 					IPAddressFamily_free(ipf1);
 					break;
 				}
@@ -346,18 +354,18 @@ verify_ipext_cert(X509_STORE_CTX *ctx, int idx, X509 *
 		}
 	}
 
-	if (!inherit || (++idx) == sk_num(ctx->chain)) {
+	if (!inherit || (++idx) == sk_num(X509_STORE_CTX_get_chain(ctx))) {
 		/* end of the line */
 		goto done;
 	}
-	x = (X509 *)sk_value(ctx->chain, idx);
+	x = (X509 *)sk_value(X509_STORE_CTX_get_chain(ctx), idx);
 	verify_ipext_cert(ctx, idx, x, vipb);
 
 done:
 	IPAddrBlocks_free(ipb);
 
 	/* If the vipb stack is now empty all ipf's matched */
-	if (sk_num(vipb) != 0) {
+	if (sk_IPAddressFamily_num(vipb) != 0) {
 		return (-1);
 	}
 
@@ -376,13 +384,13 @@ verify_ipext(X509_STORE_CTX *ctx, IPAddrBlocks *vipb)
 			   i2v_IPAddrBlocks(NULL, vipb, NULL), 8, 1);
 #endif
 
-	if (sk_num(vipb) == 0) {
+	if (sk_IPAddressFamily_num(vipb) == 0) {
 		DBG(&dbg_ver, "IPAddrBlock empty; rejecting");
 		return (-1);
 	}
 
-	for (i = 0; i < sk_num(ctx->chain); i++) {
-		x = (X509 *)sk_value(ctx->chain, i);
+	for (i = 0; i < sk_num(X509_STORE_CTX_get_chain(ctx)); i++) {
+		x = (X509 *)sk_value(X509_STORE_CTX_get_chain(ctx), i);
 
 		DBG(&dbg_ver, "%s",
 		    X509_NAME_oneline(X509_get_subject_name(x), nbuf,
@@ -391,7 +399,7 @@ verify_ipext(X509_STORE_CTX *ctx, IPAddrBlocks *vipb)
 		if (verify_ipext_cert(ctx, i, x, vipb) < 0) {
 			return (-1);
 		}
-		if (sk_num(vipb) == 0) {
+		if (sk_IPAddressFamily_num(vipb) == 0) {
 			break;
 		}
 	}
@@ -408,9 +416,9 @@ verify_ipext_chain(X509_STORE_CTX *ctx)
 
 	DBG(&dbg_ver, "Verifying IP Exts in the certificate chain");
 
-	for (i = 1; i < sk_num(ctx->chain); i++) {
-		vx = (X509 *)sk_value(ctx->chain, i - 1);
-		x = (X509 *)sk_value(ctx->chain, i);
+	for (i = 1; i < sk_num(X509_STORE_CTX_get_chain(ctx)); i++) {
+		vx = (X509 *)sk_value(X509_STORE_CTX_get_chain(ctx), i - 1);
+		x = (X509 *)sk_value(X509_STORE_CTX_get_chain(ctx), i);
 
 		DBG(&dbg_ver, "%s",
 		    X509_NAME_oneline(X509_get_subject_name(vx), nbuf,
@@ -446,7 +454,7 @@ pkixip_verify_cb(int ok, X509_STORE_CTX *ctx)
 	X509_NAME_oneline(X509_get_subject_name(x), nbuf, sizeof (nbuf));
 #endif
 	if (!ok) {
-		if (ctx->error == X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION) {
+		if (X509_STORE_CTX_get_error(ctx) == X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION) {
 			/*
 			 * OpenSSL doesn't explicitly support PKIX IP Ext,
 			 * so it throws this error when it encounters the
@@ -458,7 +466,7 @@ pkixip_verify_cb(int ok, X509_STORE_CTX *ctx)
 		} else {
 			DBG(&dbg_ver, "Not OK at %s", nbuf);
 			DBG(&dbg_ver, "%s",
-			    X509_verify_cert_error_string(ctx->error));
+			    X509_verify_cert_error_string(X509_STORE_CTX_get_error(ctx)));
 		}
 	} else {
 		DBG(&dbg_ver, "OK at %s", nbuf);
