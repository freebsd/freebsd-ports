--- Quota.xs.orig	2021-10-20 05:59:20 UTC
+++ Quota.xs
@@ -335,7 +335,7 @@ xdr_rquota(xdrs, rqp)
 #endif /* MY_XDR */
 
 #ifdef USE_EXT_RQUOTA
-bool_t
+int
 xdr_ext_getquota_args(xdrs, objp)
   XDR *xdrs;
   ext_getquota_args *objp;
