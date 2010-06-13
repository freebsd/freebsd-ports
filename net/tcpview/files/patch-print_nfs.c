--- print-nfs.c.orig	1993-04-22 13:40:18.000000000 -0700
+++ print-nfs.c	2010-06-13 08:09:51.000000000 -0700
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
@@ -54,9 +54,21 @@
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
 #include "extract.h"
@@ -170,7 +182,7 @@
 
 	/* Fetch string length; convert to host order */
 	len = *dp++;
-	NTOHL(len);
+	ntohl(len);
 
 	cp = (u_char *)dp;
 	/* Update long pointer (NFS filenames are padded to long) */
@@ -250,11 +262,13 @@
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
@@ -277,7 +291,7 @@
 			return;
 		}
 		break;
-
+/*
 #if RFS_WRITECACHE != NFSPROC_NOOP
 	case RFS_WRITECACHE:
 		printf(" writecache");
@@ -291,6 +305,7 @@
 		}
 		break;
 #endif
+*/
 	case RFS_WRITE:
 		printf(" write");
 		if ((dp = parsereq(rp, length)) != 0 &&
