--- yp.c.orig	Fri Apr 20 16:07:42 2001
+++ yp.c	Thu Jun 21 21:30:30 2001
@@ -3,6 +3,7 @@
  */
 
 #include "nis.h"
+#include <rpc/rpc.h>
 #include <rpcsvc/ypclnt.h>
 #include <rpcsvc/yp_prot.h>
 
