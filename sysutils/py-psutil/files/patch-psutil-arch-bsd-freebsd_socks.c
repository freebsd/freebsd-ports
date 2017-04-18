--- psutil/arch/bsd/freebsd_socks.c.orig	2017-03-26 08:09:27 UTC
+++ psutil/arch/bsd/freebsd_socks.c
@@ -112,10 +112,17 @@ psutil_sockaddr_matches(int family, int 
 }
 
 
+#if __FreeBSD_version >= 1200026
+static struct xtcpcb *
+psutil_search_tcplist(char *buf, struct kinfo_file *kif) {
+    struct xtcpcb *tp;
+    struct xinpcb *inp;
+#else
 static struct tcpcb *
 psutil_search_tcplist(char *buf, struct kinfo_file *kif) {
     struct tcpcb *tp;
     struct inpcb *inp;
+#endif
     struct xinpgen *xig, *oxig;
     struct xsocket *so;
 
@@ -123,9 +130,15 @@ psutil_search_tcplist(char *buf, struct 
     for (xig = (struct xinpgen *)((char *)xig + xig->xig_len);
             xig->xig_len > sizeof(struct xinpgen);
             xig = (struct xinpgen *)((char *)xig + xig->xig_len)) {
+#if __FreeBSD_version >= 1200026
+	tp = (struct xtcpcb *)xig;
+	inp = &tp->xt_inp;
+	so = &inp->xi_socket;
+#else
         tp = &((struct xtcpcb *)xig)->xt_tp;
         inp = &((struct xtcpcb *)xig)->xt_inp;
         so = &((struct xtcpcb *)xig)->xt_socket;
+#endif
 
         if (so->so_type != kif->kf_sock_type ||
                 so->xso_family != kif->kf_sock_domain ||
@@ -208,7 +221,11 @@ int psutil_gather_inet(int proto, PyObje
     struct xinpgen *xig, *exig;
     struct xinpcb *xip;
     struct xtcpcb *xtp;
+#if __FreeBSD_version >= 1200026
+    struct xinpcb *inp;
+#else
     struct inpcb *inp;
+#endif
     struct xsocket *so;
     const char *varname = NULL;
     size_t len, bufsize;
@@ -273,8 +290,13 @@ int psutil_gather_inet(int proto, PyObje
                     goto error;
                 }
                 inp = &xtp->xt_inp;
+#if __FreeBSD_version >= 1200026
+		so = &inp->xi_socket;
+		status = xtp->t_state;
+#else
                 so = &xtp->xt_socket;
                 status = xtp->xt_tp.t_state;
+#endif
                 break;
             case IPPROTO_UDP:
                 xip = (struct xinpcb *)xig;
@@ -283,7 +305,11 @@ int psutil_gather_inet(int proto, PyObje
                                  "struct xinpcb size mismatch");
                     goto error;
                 }
+#if __FreeBSD_version >= 1200026
+		inp = xip;
+#else
                 inp = &xip->xi_inp;
+#endif
                 so = &xip->xi_socket;
                 status = PSUTIL_CONN_NONE;
                 break;
@@ -477,7 +503,11 @@ psutil_proc_connections(PyObject *self, 
     struct kinfo_file *freep = NULL;
     struct kinfo_file *kif;
     char *tcplist = NULL;
+#if __FreeBSD_version >= 1200026
+    struct xtcpcb *tcp;
+#else
     struct tcpcb *tcp;
+#endif
 
     PyObject *py_retlist = PyList_New(0);
     PyObject *py_tuple = NULL;
