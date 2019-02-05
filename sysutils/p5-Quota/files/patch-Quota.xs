--- Quota.xs.orig	2013-08-15 04:56:35 UTC
+++ Quota.xs
@@ -309,7 +309,7 @@ struct rquota *rqp;
 #endif /* MY_XDR */
 
 #ifdef USE_EXT_RQUOTA
-bool_t
+int
 xdr_ext_getquota_args(xdrs, objp)
 XDR *xdrs;
 ext_getquota_args *objp;
