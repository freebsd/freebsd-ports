--- src/platform/posix/posix_ipcconn.c.orig	2020-08-02 19:33:36 UTC
+++ src/platform/posix/posix_ipcconn.c
@@ -363,7 +363,7 @@ ipc_peerid(ipc_conn *c, uint64_t *euid, uint64_t *egid
 	*prid = uc.pid;
 	*znid = (uint64_t) -1;
 	return (0);
-#elif defined(NNG_HAVE_LOCALPEERCRED)
+#elif defined(NNG_HAVE_LOCALPEERCRED) && !defined(__FreeBSD__)
 	struct xucred xu;
 	socklen_t     len = sizeof(xu);
 	if (getsockopt(fd, SOL_LOCAL, LOCAL_PEERCRED, &xu, &len) != 0) {
