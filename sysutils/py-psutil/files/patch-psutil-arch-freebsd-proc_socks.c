--- psutil/arch/freebsd/proc_socks.c.orig	2017-08-03 16:14:27 UTC
+++ psutil/arch/freebsd/proc_socks.c
@@ -136,7 +136,11 @@ psutil_search_tcplist(char *buf, struct 
         if (kif->kf_sock_domain == AF_INET) {
             if (!psutil_sockaddr_matches(
                     AF_INET, inp->inp_lport, &inp->inp_laddr,
+#if __FreeBSD_version >= 1200031
+                    &kif->kf_un.kf_sock.kf_sa_local))
+#else
                     &kif->kf_sa_local))
+#endif
                 continue;
             if (!psutil_sockaddr_matches(
                     AF_INET, inp->inp_fport, &inp->inp_faddr,
@@ -145,7 +149,11 @@ psutil_search_tcplist(char *buf, struct 
         } else {
             if (!psutil_sockaddr_matches(
                     AF_INET6, inp->inp_lport, &inp->in6p_laddr,
+#if __FreeBSD_version >= 1200031
+                    &kif->kf_un.kf_sock.kf_sa_local))
+#else
                     &kif->kf_sa_local))
+#endif
                 continue;
             if (!psutil_sockaddr_matches(
                     AF_INET6, inp->inp_fport, &inp->in6p_faddr,
@@ -243,7 +251,11 @@ psutil_proc_connections(PyObject *self, 
                 inet_ntop(
                     kif->kf_sock_domain,
                     psutil_sockaddr_addr(kif->kf_sock_domain,
+#if __FreeBSD_version >= 1200031
+                                         &kif->kf_un.kf_sock.kf_sa_local),
+#else
                                          &kif->kf_sa_local),
+#endif
                     lip,
                     sizeof(lip));
                 inet_ntop(
@@ -253,7 +265,11 @@ psutil_proc_connections(PyObject *self, 
                     rip,
                     sizeof(rip));
                 lport = htons(psutil_sockaddr_port(kif->kf_sock_domain,
+#if __FreeBSD_version >= 1200031
+                                                   &kif->kf_un.kf_sock.kf_sa_local));
+#else
                                                    &kif->kf_sa_local));
+#endif
                 rport = htons(psutil_sockaddr_port(kif->kf_sock_domain,
                                                    &kif->kf_sa_peer));
 
@@ -287,7 +303,11 @@ psutil_proc_connections(PyObject *self, 
             else if (kif->kf_sock_domain == AF_UNIX) {
                 struct sockaddr_un *sun;
 
+#if __FreeBSD_version >= 1200031
+                sun = (struct sockaddr_un *)&kif->kf_un.kf_sock.kf_sa_local;
+#else
                 sun = (struct sockaddr_un *)&kif->kf_sa_local;
+#endif
                 snprintf(
                     path, sizeof(path), "%.*s",
                     (int)(sun->sun_len - (sizeof(*sun) - sizeof(sun->sun_path))),
