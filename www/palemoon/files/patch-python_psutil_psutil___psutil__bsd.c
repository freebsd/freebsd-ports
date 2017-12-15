--- python/psutil/psutil/_psutil_bsd.c.orig	2017-11-14 14:36:13 UTC
+++ python/psutil/psutil/_psutil_bsd.c
@@ -12,6 +12,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <err.h>
 #include <signal.h>
 #include <fcntl.h>
 #include <paths.h>
@@ -957,11 +958,19 @@ psutil_sockaddr_matches(int family, int port, void *pc
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
 
@@ -969,9 +978,15 @@ psutil_search_tcplist(char *buf, struct kinfo_file *ki
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
@@ -981,20 +996,36 @@ psutil_search_tcplist(char *buf, struct kinfo_file *ki
         if (kif->kf_sock_domain == AF_INET) {
             if (!psutil_sockaddr_matches(
                     AF_INET, inp->inp_lport, &inp->inp_laddr,
+#if __FreeBSD_version < 1200031
                     &kif->kf_sa_local))
+#else
+                    &kif->kf_un.kf_sock.kf_sa_local))
+#endif
                 continue;
             if (!psutil_sockaddr_matches(
                     AF_INET, inp->inp_fport, &inp->inp_faddr,
+#if __FreeBSD_version < 1200031
                     &kif->kf_sa_peer))
+#else
+                    &kif->kf_un.kf_sock.kf_sa_peer))
+#endif
                 continue;
         } else {
             if (!psutil_sockaddr_matches(
                     AF_INET6, inp->inp_lport, &inp->in6p_laddr,
+#if __FreeBSD_version < 1200031
                     &kif->kf_sa_local))
+#else
+                    &kif->kf_un.kf_sock.kf_sa_local))
+#endif
                 continue;
             if (!psutil_sockaddr_matches(
                     AF_INET6, inp->inp_fport, &inp->in6p_faddr,
+#if __FreeBSD_version < 1200031
                     &kif->kf_sa_peer))
+#else
+                    &kif->kf_un.kf_sock.kf_sa_peer))
+#endif
                 continue;
         }
 
@@ -1019,7 +1050,11 @@ psutil_proc_connections(PyObject *self, PyObject *args
     struct kinfo_file *freep = NULL;
     struct kinfo_file *kif;
     char *tcplist = NULL;
+#if __FreeBSD_version >= 1200026
+    struct xtcpcb *tcp;
+#else
     struct tcpcb *tcp;
+#endif
 
     PyObject *retList = PyList_New(0);
     PyObject *tuple = NULL;
@@ -1094,19 +1129,35 @@ psutil_proc_connections(PyObject *self, PyObject *args
                 inet_ntop(
                     kif->kf_sock_domain,
                     psutil_sockaddr_addr(kif->kf_sock_domain,
+#if __FreeBSD_version < 1200031
                                          &kif->kf_sa_local),
+#else
+                                         &kif->kf_un.kf_sock.kf_sa_local),
+#endif
                     lip,
                     sizeof(lip));
                 inet_ntop(
                     kif->kf_sock_domain,
                     psutil_sockaddr_addr(kif->kf_sock_domain,
+#if __FreeBSD_version < 1200031
                                          &kif->kf_sa_peer),
+#else
+                                         &kif->kf_un.kf_sock.kf_sa_peer),
+#endif
                     rip,
                     sizeof(rip));
                 lport = htons(psutil_sockaddr_port(kif->kf_sock_domain,
+#if __FreeBSD_version < 1200031
                                                    &kif->kf_sa_local));
+#else
+                                                   &kif->kf_un.kf_sock.kf_sa_local));
+#endif
                 rport = htons(psutil_sockaddr_port(kif->kf_sock_domain,
+#if __FreeBSD_version < 1200031
                                                    &kif->kf_sa_peer));
+#else
+                                                   &kif->kf_un.kf_sock.kf_sa_peer));
+#endif
 
                 // construct python tuple/list
                 laddr = Py_BuildValue("(si)", lip, lport);
@@ -1137,10 +1188,14 @@ psutil_proc_connections(PyObject *self, PyObject *args
             else if (kif->kf_sock_domain == AF_UNIX) {
                 struct sockaddr_un *sun;
 
+#if __FreeBSD_version < 1200031
                 sun = (struct sockaddr_un *)&kif->kf_sa_local;
+#else
+                sun = (struct sockaddr_un *)&kif->kf_un.kf_sock.kf_sa_local;
+#endif
                 snprintf(
                     path, sizeof(path), "%.*s",
-                    (sun->sun_len - (sizeof(*sun) - sizeof(sun->sun_path))),
+                    (int)(sun->sun_len - (sizeof(*sun) - sizeof(sun->sun_path))),
                     sun->sun_path);
 
                 tuple = Py_BuildValue("(iiisOi)",
@@ -1250,7 +1305,7 @@ void remove_spaces(char *str) {
     do
         while (*p2 == ' ')
             p2++;
-    while (*p1++ = *p2++);
+    while ((*p1++ = *p2++));
 }
 
 
@@ -1779,7 +1834,11 @@ int psutil_gather_inet(int proto, PyObject *py_retlist
     struct xinpgen *xig, *exig;
     struct xinpcb *xip;
     struct xtcpcb *xtp;
+#if __FreeBSD_version >= 1200026
+    struct xinpcb *inp;
+#else
     struct inpcb *inp;
+#endif
     struct xsocket *so;
     struct sock *sock;
     const char *varname;
@@ -1849,13 +1908,22 @@ int psutil_gather_inet(int proto, PyObject *py_retlist
                 PyErr_Format(PyExc_RuntimeError, "struct xinpcb size mismatch");
                 goto error;
             }
+#if __FreeBSD_version >= 1200026
+            inp = xip;
+#else
             inp = &xip->xi_inp;
+#endif
             so = &xip->xi_socket;
             break;
         }
 
+#if __FreeBSD_version >= 1200026
+        inp = xip;
+	so = xtp->t_state;
+#else
         inp = &xtp->xt_inp;
         so = &xtp->xt_socket;
+#endif
         char lip[200], rip[200];
         int family, lport, rport, pid, status;
 
@@ -1865,7 +1933,11 @@ int psutil_gather_inet(int proto, PyObject *py_retlist
             continue;
         lport = ntohs(inp->inp_lport);
         rport = ntohs(inp->inp_fport);
+#if __FreeBSD_version >= 1200026
+        status = xtp->t_state;
+#else
         status = xtp->xt_tp.t_state;
+#endif
 
         if (inp->inp_vflag & INP_IPV4) {
             family = AF_INET;
@@ -1985,7 +2057,7 @@ int psutil_gather_unix(int proto, PyObject *py_retlist
 
         sun = (struct sockaddr_un *)&xup->xu_addr;
         snprintf(path, sizeof(path), "%.*s",
-                 (sun->sun_len - (sizeof(*sun) - sizeof(sun->sun_path))),
+                 (int)(sun->sun_len - (sizeof(*sun) - sizeof(sun->sun_path))),
                  sun->sun_path);
 
         tuple = Py_BuildValue("(iiisOii)", -1, AF_UNIX, proto, path, Py_None,
