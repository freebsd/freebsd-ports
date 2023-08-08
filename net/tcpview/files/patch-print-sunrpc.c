--- print-sunrpc.c.orig	1993-04-22 20:40:27 UTC
+++ print-sunrpc.c
@@ -38,10 +38,10 @@ static char rcsid[] =
 #include <sys/time.h>
 #include <errno.h>
 #include <rpc/types.h>
+#include <rpc/xdr.h>
 #include <rpc/auth.h>
 #include <rpc/auth_unix.h>
 #include <rpc/svc.h>
-#include <rpc/xdr.h>
 #include <rpc/rpc_msg.h>
 
 #include <rpc/pmap_prot.h>
