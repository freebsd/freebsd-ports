--- print-nfs.c.orig	Thu Apr 22 22:40:18 1993
+++ print-nfs.c	Thu Feb 13 18:53:20 2003
@@ -38,10 +38,10 @@
 #include <sys/time.h>
 #include <errno.h>
 #include <rpc/types.h>
+#include <rpc/xdr.h>
 #include <rpc/auth.h>
 #include <rpc/auth_unix.h>
 #include <rpc/svc.h>
-#include <rpc/xdr.h>
 #include <rpc/rpc_msg.h>
 
 #include <ctype.h>
@@ -54,9 +54,15 @@
 /* These must come after interface.h for BSD. */
 #if BSD >= 199006
 #include <sys/ucred.h>
-#include <nfs/nfsv2.h>
+#include <sys/mount.h>
+/*#include <rpcsvc/nfs_prot.h>*/
+#define	NFSPROC_WRITECACHE ((unsigned long)(7))
+#define	NFSPROC_ROOT ((unsigned long)(3))
+#define	NFSPROC_STATFS ((unsigned long)(17))
+
+#include <nfs/rpcv2.h>
+#include <nfs/nfsproto.h>
 #endif
-#include <nfs/nfs.h>
 
 #include "addrtoname.h"
 #include "extract.h"
@@ -250,11 +256,13 @@
 			return;
 		break;
 
+/*
 #if RFS_ROOT != NFSPROC_NOOP
 	case RFS_ROOT:
 		printf(" root");
 		break;
 #endif
+*/
 	case RFS_LOOKUP:
 		printf(" lookup");
 		if ((dp = parsereq(rp, length)) != 0 && parsefhn(dp) != 0)
@@ -277,7 +285,7 @@
 			return;
 		}
 		break;
-
+/*
 #if RFS_WRITECACHE != NFSPROC_NOOP
 	case RFS_WRITECACHE:
 		printf(" writecache");
@@ -291,6 +299,7 @@
 		}
 		break;
 #endif
+*/
 	case RFS_WRITE:
 		printf(" write");
 		if ((dp = parsereq(rp, length)) != 0 &&
