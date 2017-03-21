--- src/tcpconns.c.orig	2017-03-21 00:18:33.371554000 -0700
+++ src/tcpconns.c	2017-03-21 00:21:09.631089000 -0700
@@ -745,9 +745,15 @@
   for (in_ptr = (struct xinpgen *)(((char *)in_orig) + in_orig->xig_len);
        in_ptr->xig_len > sizeof(struct xinpgen);
        in_ptr = (struct xinpgen *)(((char *)in_ptr) + in_ptr->xig_len)) {
+#if __FreeBSD_version >= 1200026
+    struct xtcpcb *tp = (struct xtcpcb *)in_ptr;
+    struct xinpcb *inp = &tp->xt_inp;
+    struct xsocket *so = &inp->xi_socket;
+#else
     struct tcpcb *tp = &((struct xtcpcb *)in_ptr)->xt_tp;
     struct inpcb *inp = &((struct xtcpcb *)in_ptr)->xt_inp;
     struct xsocket *so = &((struct xtcpcb *)in_ptr)->xt_socket;
+#endif
 
     /* Ignore non-TCP sockets */
     if (so->xso_protocol != IPPROTO_TCP)
