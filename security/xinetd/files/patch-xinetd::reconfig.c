--- xinetd/reconfig.c.orig	Sun Jul 15 04:31:28 2001
+++ xinetd/reconfig.c	Fri Feb  8 16:05:56 2002
@@ -14,6 +14,7 @@
 #include <memory.h>
 #include <stdlib.h>
 #include <netinet/in.h>
+#include <osreldate.h>
 #ifndef NO_RPC
  #ifdef HAVE_RPC_PMAP_CLNT_H
   #ifdef __sun
@@ -22,6 +23,10 @@
   #endif
   #include <rpc/types.h>
   #include <rpc/xdr.h>
+  #if __FreeBSD_version >= 500029
+   #include <rpc/auth.h>
+   #include <rpc/clnt.h>
+  #endif
   #include <rpc/pmap_clnt.h>
  #endif
 #endif
