--- nfs_prot_xdr.c.orig	2013-12-28 16:36:09.000000000 +0100
+++ nfs_prot_xdr.c	2013-12-28 16:36:34.000000000 +0100
@@ -4,6 +4,7 @@
  */
 
 #include "nfs_prot.h"
+#define	xdr_u_quad_t	xdr_u_int64_t
 
 bool_t
 xdr_cookieverf3 (XDR *xdrs, cookieverf3 objp)
