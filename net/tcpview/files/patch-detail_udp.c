--- detail-udp.c.orig	1993-04-22 13:39:55.000000000 -0700
+++ detail-udp.c	2010-06-13 08:09:33.000000000 -0700
@@ -37,6 +37,7 @@
 #endif
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
@@ -50,12 +51,21 @@
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
