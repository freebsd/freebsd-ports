--- print-udp.c.orig	Thu Apr 22 22:40:29 1993
+++ print-udp.c	Thu Feb 13 18:54:06 2003
@@ -39,10 +39,10 @@
 #include <errno.h>
 #include <sys/time.h>
 #include <rpc/types.h>
+#include <rpc/xdr.h>
 #include <rpc/auth.h>
 #include <rpc/auth_unix.h>
 #include <rpc/svc.h>
-#include <rpc/xdr.h>
 #include <rpc/rpc_msg.h>
 
 #ifdef TCPVIEW
@@ -53,9 +53,10 @@
 /* These must come after interface.h for BSD. */
 #if BSD >= 199006
 #include <sys/ucred.h>
-#include <nfs/nfsv2.h>
+#include <sys/mount.h>
+#include <nfs/rpcv2.h>
+#include <nfs/nfsproto.h>
 #endif
-#include <nfs/nfs.h>
 
 #include "addrtoname.h"
 #include "appletalk.h"
