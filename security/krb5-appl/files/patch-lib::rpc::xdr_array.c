--- lib/rpc/xdr_array.c.orig	Fri Feb 13 20:27:23 1998
+++ lib/rpc/xdr_array.c	Fri Aug  2 13:03:55 2002
@@ -40,6 +40,7 @@
  * arrays.  See xdr.h for more info on the interface to xdr.
  */
 
+#include <limits.h>
 #include <stdio.h>
 
 #include <gssrpc/types.h>
@@ -75,7 +76,8 @@
 		return (FALSE);
 	}
 	c = *sizep;
-	if ((c > maxsize) && (xdrs->x_op != XDR_FREE)) {
+	if ((c > maxsize || UINT_MAX/elsize < c) &&
+	    (xdrs->x_op != XDR_FREE)) {
 		return (FALSE);
 	}
 	nodesize = c * elsize;
