--- support/ethertalk/aarpd_xdr.c.orig	Sat Mar 20 13:39:44 2004
+++ support/ethertalk/aarpd_xdr.c	Sat Mar 20 13:40:02 2004
@@ -11,7 +11,7 @@
 	XDR *xdrs;
 	etheraddr objp;
 {
-	if (!xdr_vector(xdrs, (char *)objp, 6, sizeof(u_char), xdr_u_char)) {
+	if (!xdr_vector(xdrs, (char *)objp, 6, sizeof(u_char), (xdrproc_t)xdr_u_char)) {
 		return (FALSE);
 	}
 	return (TRUE);
@@ -22,7 +22,7 @@
 	XDR *xdrs;
 	bridgeaddr objp;
 {
-	if (!xdr_vector(xdrs, (char *)objp, 4, sizeof(u_char), xdr_u_char)) {
+	if (!xdr_vector(xdrs, (char *)objp, 4, sizeof(u_char), (xdrproc_t)xdr_u_char)) {
 		return (FALSE);
 	}
 	return (TRUE);
