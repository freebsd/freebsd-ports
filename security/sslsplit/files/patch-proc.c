--- proc.c.orig	2017-03-21 00:13:06.166567000 -0700
+++ proc.c	2017-03-21 00:14:38.957451000 -0700
@@ -175,7 +175,11 @@
 
 	struct xinpgen *xig, *exig, *txig;
 	struct xtcpcb *xtp;
+#if __FreeBSD_version >= 1200026
+	struct xinpcb *inp;
+#else
 	struct inpcb *inp;
+#endif
 	struct xsocket *so;
 
 	if (proc_freebsd_getfiles(&xfiles, &nxfiles) == -1) {
@@ -197,7 +201,11 @@
 			return -1;
 		}
 		inp = &xtp->xt_inp;
+#if __FreeBSD_version >= 1200026
+		so = &inp->xi_socket;
+#else
 		so = &xtp->xt_socket;
+#endif
 
 		if (!(so->so_state & SS_ISCONNECTED))
 			/* we are only interested in connected sockets */
