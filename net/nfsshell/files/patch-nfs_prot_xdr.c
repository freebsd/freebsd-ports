--- nfs_prot_xdr.c.orig	2013-05-10 21:40:04 UTC
+++ nfs_prot_xdr.c
@@ -4,6 +4,7 @@
  */
 
 #include "nfs_prot.h"
+#define	xdr_u_quad_t	xdr_u_int64_t
 
 bool_t
 xdr_cookieverf3 (XDR *xdrs, cookieverf3 objp)
