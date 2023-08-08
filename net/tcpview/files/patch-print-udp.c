--- print-udp.c.orig	1993-04-22 20:40:29 UTC
+++ print-udp.c
@@ -39,10 +39,10 @@ static char rcsid[] =
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
@@ -53,9 +53,16 @@ static char rcsid[] =
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
 #endif
-#include <nfs/nfs.h>
+#endif
 
 #include "addrtoname.h"
 #include "appletalk.h"
