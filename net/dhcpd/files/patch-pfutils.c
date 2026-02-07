--- pfutils.c.orig	2024-02-29 18:24:10.373450000 +0000
+++ pfutils.c	2024-02-29 18:35:27.247364000 +0000
@@ -190,9 +190,15 @@ pf_kill_state(int fd, struct in_addr ip)
 	    sizeof(psk.psk_src.addr.v.a.addr));
 	memset(&psk.psk_src.addr.v.a.mask, 0xff,
 	    sizeof(psk.psk_src.addr.v.a.mask));
+#if (defined(__FreeBSD_version) && (__FreeBSD_version < 1500000))
 	if (ioctl(fd, DIOCKILLSTATES, &psk) == -1) {
 		log_warn("DIOCKILLSTATES failed");
 	}
+#else
+	if (ioctl(fd, DIOCKILLSTATESNV, &psk) == -1) {
+		log_warn("DIOCKILLSTATESNV failed");
+	}
+#endif
 
 	/* Kill all states to target */
 	memset(&psk.psk_src, 0, sizeof(psk.psk_src));
@@ -200,9 +206,15 @@ pf_kill_state(int fd, struct in_addr ip)
 	    sizeof(psk.psk_dst.addr.v.a.addr));
 	memset(&psk.psk_dst.addr.v.a.mask, 0xff,
 	    sizeof(psk.psk_dst.addr.v.a.mask));
+#if (defined(__FreeBSD_version) && (__FreeBSD_version < 1500000))
 	if (ioctl(fd, DIOCKILLSTATES, &psk) == -1) {
 		log_warn("DIOCKILLSTATES failed");
 	}
+#else
+	if (ioctl(fd, DIOCKILLSTATESNV, &psk) == -1) {
+		log_warn("DIOCKILLSTATESNV failed");
+	}
+#endif
 }
 
 /* inspired by ("stolen") from usr.bin/ssh/atomicio.c */
