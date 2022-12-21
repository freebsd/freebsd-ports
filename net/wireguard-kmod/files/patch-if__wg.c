Chase udp_tun_func_t typedef change in FreeBSD 14-current (bb77f0)

Submitted by:	Stefan Haller <stefan+freebsd@stha.de>,
		Guido Falsi <madpilot@FreeBSD.org>
Obtained from:	https://bugs.freebsd.org/266914
Link:		https://freshbsd.org/freebsd/src/commit/bb77f0c2049311f0661c2493838d81a5a66c449c
--- if_wg.c.orig	2022-06-15 14:11:06 UTC
+++ if_wg.c
@@ -693,7 +693,11 @@ wg_socket_init(struct wg_softc *sc, in_port_t port)
 	if (rc)
 		goto out;
 
+#if __FreeBSD_version >= 1400067
+	rc = udp_set_kernel_tunneling(so4, wg_input, NULL, sc);
+#else
 	rc = udp_set_kernel_tunneling(so4, (udp_tun_func_t)wg_input, NULL, sc);
+#endif
 	/*
 	 * udp_set_kernel_tunneling can only fail if there is already a tunneling function set.
 	 * This should never happen with a new socket.
@@ -704,7 +708,11 @@ wg_socket_init(struct wg_softc *sc, in_port_t port)
 	rc = socreate(AF_INET6, &so6, SOCK_DGRAM, IPPROTO_UDP, cred, td);
 	if (rc)
 		goto out;
+#if __FreeBSD_version >= 1400067
+	rc = udp_set_kernel_tunneling(so6, wg_input, NULL, sc);
+#else
 	rc = udp_set_kernel_tunneling(so6, (udp_tun_func_t)wg_input, NULL, sc);
+#endif
 	MPASS(rc == 0);
 #endif
 
