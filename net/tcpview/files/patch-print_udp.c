--- print-udp.c.orig	1993-04-22 13:40:29.000000000 -0700
+++ print-udp.c	2010-06-13 08:09:39.000000000 -0700
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
@@ -53,9 +53,16 @@
 /* These must come after interface.h for BSD. */
 #if BSD >= 199006
 #include <sys/ucred.h>
-#include <nfs/nfsv2.h>
+#include <sys/mount.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 800100
+#include <fs/nfs/nfsport.h>
+#include <fs/nfs/rpcv2.h>
+#include <fs/nfs/nfsproto.h>
+#else
+#include <nfs/rpcv2.h>
+#include <nfs/nfsproto.h>
+#endif
 #endif
-#include <nfs/nfs.h>
 
 #include "addrtoname.h"
 #include "appletalk.h"
