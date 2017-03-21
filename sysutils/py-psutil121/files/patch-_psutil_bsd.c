--- psutil/_psutil_bsd.c.orig	2017-03-21 00:39:17.505652000 -0700
+++ psutil/_psutil_bsd.c	2017-03-21 00:41:20.821739000 -0700
@@ -917,11 +917,19 @@
         psutil_sockaddr_addrlen(family)) == 0);
 }
 
+#if __FreeBSD_version >= 1200026
+static struct xtcpcb *
+psutil_search_tcplist(char *buf, struct kinfo_file *kif)
+{
+    struct xtcpcb *tp;
+    struct xinpcb *inp;
+#else
 static struct tcpcb *
 psutil_search_tcplist(char *buf, struct kinfo_file *kif)
 {
     struct tcpcb *tp;
     struct inpcb *inp;
+#endif
     struct xinpgen *xig, *oxig;
     struct xsocket *so;
 
@@ -929,9 +937,15 @@
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
@@ -976,7 +990,11 @@
     struct kinfo_file *kif;
     struct kinfo_proc kipp;
     char *tcplist = NULL;
+#if __FreeBSD_version >= 1200026
+    struct xtcpcb *tcp;
+#else
     struct tcpcb *tcp;
+#endif
 
     PyObject *retList = PyList_New(0);
     PyObject *tuple = NULL;
