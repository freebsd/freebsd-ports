--- rstat.x	Sat Mar  6 17:26:17 2004
+++ /tmp/rstat.x.patch	Sat Mar  6 17:26:11 2004
@@ -52,7 +52,7 @@
 % */
 %
 %bool_t
-%#ifdef __STDC__
+%#if __STDC__
 %xdr_timeval(XDR *xdrs, struct timeval *tvp)
 %#else /* K&R C */
 %xdr_timeval(xdrs, tvp)
