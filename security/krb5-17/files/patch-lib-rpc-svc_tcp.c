=== lib/rpc/svc_tcp.c
==================================================================
--- lib/rpc/svc_tcp.c	(revision 1666)
+++ lib/rpc/svc_tcp.c	(local)
@@ -54,6 +54,14 @@
 extern errno;
 */
 
+#ifndef FD_SETSIZE
+#ifdef NBBY
+#define NOFILE (sizeof(int) * NBBY)
+#else
+#define NOFILE (sizeof(int) * 8)
+#endif
+#endif
+
 /*
  * Ops vector for TCP/IP based rpc service handle
  */
@@ -215,6 +223,19 @@
 	register SVCXPRT *xprt;
 	register struct tcp_conn *cd;
  
+#ifdef FD_SETSIZE
+	if (fd >= FD_SETSIZE) {
+		(void) fprintf(stderr, "svc_tcp: makefd_xprt: fd too high\n");
+		xprt = NULL;
+		goto done;
+	}
+#else
+	if (fd >= NOFILE) {
+		(void) fprintf(stderr, "svc_tcp: makefd_xprt: fd too high\n");
+		xprt = NULL;
+		goto done;
+	}
+#endif
 	xprt = (SVCXPRT *)mem_alloc(sizeof(SVCXPRT));
 	if (xprt == (SVCXPRT *)NULL) {
 		(void) fprintf(stderr, "svc_tcp: makefd_xprt: out of memory\n");
@@ -271,6 +292,10 @@
 	 * make a new transporter (re-uses xprt)
 	 */
 	xprt = makefd_xprt(sock, r->sendsize, r->recvsize);
+	if (xprt == NULL) {
+		close(sock);
+		return (FALSE);
+	}
 	xprt->xp_raddr = addr;
 	xprt->xp_addrlen = len;
 	xprt->xp_laddr = laddr;

