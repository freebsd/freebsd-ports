--- detail-udp.c.orig	Thu Apr 22 22:39:55 1993
+++ detail-udp.c	Thu Feb 13 18:57:17 2003
@@ -37,6 +37,7 @@
 #endif
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
@@ -50,12 +51,15 @@
 #include <errno.h>
 #include <sys/time.h>
 #include <rpc/types.h>
+#include <rpc/xdr.h>
 #include <rpc/auth.h>
 #include <rpc/auth_unix.h>
 #include <rpc/svc.h>
-#include <rpc/xdr.h>
 #include <rpc/rpc_msg.h>
-#include <nfs/nfs.h>
+#include <sys/ucred.h> 
+#include <sys/mount.h>
+#include <nfs/rpcv2.h>
+#include <nfs/nfsproto.h>
 
 #include "interface.h"
 #include "addrtoname.h"
