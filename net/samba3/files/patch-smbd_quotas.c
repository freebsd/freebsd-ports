--- smbd/quotas.c.orig	Wed Sep  1 17:43:45 2004
+++ smbd/quotas.c	Wed Sep  1 17:44:32 2004
@@ -938,7 +938,6 @@
 #include <rpc/rpc.h>
 #include <rpc/types.h>
 #include <rpcsvc/rquota.h>
-#include <rpc/nettype.h>
 #include <rpc/xdr.h>
 
 static int quotastat;
