--- xinetd/service.c.orig	Mon Aug 13 03:58:57 2001
+++ xinetd/service.c	Fri Feb  8 16:06:16 2002
@@ -19,6 +19,7 @@
 #include <time.h>
 #include <errno.h>
 #include <netinet/in.h>
+#include <osreldate.h>
 #ifndef NO_RPC
  #ifdef HAVE_RPC_PMAP_CLNT_H
   #ifdef __sun
@@ -27,7 +28,10 @@
   #endif
   #include <rpc/types.h>
   #include <rpc/xdr.h>
-  #include <rpc/pmap_clnt.h>
+  #if __FreeBSD__version >= 500029
+   #include <rpc/auth.h>
+   #include <rpc/pmap_clnt.h>
+  #endif
  #endif
 #endif
 
