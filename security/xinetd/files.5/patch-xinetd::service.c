--- xinetd/service.c.orig	Wed Oct 16 09:25:06 2002
+++ xinetd/service.c	Wed Oct 16 09:25:26 2002
@@ -31,6 +31,8 @@
   #endif
   #include <rpc/types.h>
   #include <rpc/xdr.h>
+  #include <rpc/auth.h>
+  #include <rpc/clnt.h>
   #include <rpc/pmap_clnt.h>
  #endif
  #include <rpc/rpc.h>
