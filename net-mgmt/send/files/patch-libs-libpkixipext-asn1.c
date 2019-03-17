--- libs/libpkixipext/asn1.c.orig	2019-02-27 16:25:45 UTC
+++ libs/libpkixipext/asn1.c
@@ -187,9 +187,8 @@ i2v_IPAddressChoice(X509V3_EXT_METHOD *method, IPAddre
 		break;
 	case IPA_CHOICE_AOR:
 		X509V3_add_value("        Prefix or Range", NULL, &extlist);
-		for (i = 0; i < sk_num(ipc->u.addressesOrRanges); i++) {
-			aor = (IPAddressOrRange *)
-				sk_value(ipc->u.addressesOrRanges, i);
+		for (i = 0; i < sk_IPAddressOrRange_num(ipc->u.addressesOrRanges); i++) {
+			aor = sk_IPAddressOrRange_value(ipc->u.addressesOrRanges, i);
 			i2v_IPAddressOrRange(method, aor, extlist, af);
 		}
 		break;
@@ -265,8 +264,8 @@ i2v_IPAddrBlocks(X509V3_EXT_METHOD *method, IPAddrBloc
 		return (NULL);
 	}
 
-	for (i = 0; i < sk_num(ipb); i++) {
-		ipf = (IPAddressFamily *)sk_value(ipb, i);
+	for (i = 0; i < sk_IPAddressFamily_num(ipb); i++) {
+		ipf = sk_IPAddressFamily_value(ipb, i);
 		i2v_IPAddressFamily(method, ipf, extlist);
 	}
 
