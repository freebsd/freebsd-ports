--- detail-udp.c.orig	1993-04-22 20:39:55 UTC
+++ detail-udp.c
@@ -37,6 +37,7 @@ static char rcsid[] =
 #endif
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
@@ -50,12 +51,21 @@ static char rcsid[] =
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
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 800100
+#include <fs/nfs/nfsport.h>
+#include <fs/nfs/rpcv2.h>
+#include <fs/nfs/nfsproto.h>
+#else
+#include <nfs/rpcv2.h>
+#include <nfs/nfsproto.h>
+#endif
 
 #include "interface.h"
 #include "addrtoname.h"
