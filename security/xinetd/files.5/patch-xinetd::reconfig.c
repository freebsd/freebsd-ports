--- xinetd/reconfig.c.orig	Wed Oct 16 09:22:22 2002
+++ xinetd/reconfig.c	Wed Oct 16 09:24:09 2002
@@ -23,6 +23,8 @@
   #endif
   #include <rpc/types.h>
   #include <rpc/xdr.h>
+  #include <rpc/auth.h>
+  #include <rpc/clnt.h>
   #include <rpc/pmap_clnt.h>
  #endif
  #include <rpc/rpc.h>
