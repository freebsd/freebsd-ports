--- dialects/freebsd/dlsof.h.orig	2022-08-17 09:12:09 UTC
+++ dialects/freebsd/dlsof.h
@@ -183,7 +183,6 @@ int     getmntinfo(struct statfs **, int);
 #undef	_KVM_VNODE
 # endif	/* defined(HAS_KVM_VNODE) */
 
-#include <net/raw_cb.h>
 #include <sys/domain.h>
 #define	pmap	RPC_pmap
 #include <rpc/rpc.h>
