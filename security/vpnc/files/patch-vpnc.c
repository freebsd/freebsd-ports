--- ./vpnc.c.orig	2011-02-25 20:17:00.000000000 +0100
+++ ./vpnc.c	2011-02-25 20:18:49.000000000 +0100
@@ -2861,28 +2861,34 @@
 		free(dh_shared_secret);
 		free_isakmp_packet(r);
 		
-		if ((opt_natt_mode == NATT_CISCO_UDP) && s->ipsec.peer_udpencap_port) {
-			s->esp_fd = make_socket(s, opt_udpencapport, s->ipsec.peer_udpencap_port);
-			s->ipsec.encap_mode = IPSEC_ENCAP_UDP_TUNNEL;
-			s->ipsec.natt_active_mode = NATT_ACTIVE_CISCO_UDP;
-		} else if (s->ipsec.encap_mode != IPSEC_ENCAP_TUNNEL) {
-			s->esp_fd = s->ike_fd;
-		} else {
+		if (s->esp_fd == 0) {
+			if ((opt_natt_mode == NATT_CISCO_UDP) && s->ipsec.peer_udpencap_port) {
+				s->esp_fd = make_socket(s, opt_udpencapport, s->ipsec.peer_udpencap_port);
+				s->ipsec.encap_mode = IPSEC_ENCAP_UDP_TUNNEL;
+				s->ipsec.natt_active_mode = NATT_ACTIVE_CISCO_UDP;
+			} else if (s->ipsec.encap_mode != IPSEC_ENCAP_TUNNEL) {
+				s->esp_fd = s->ike_fd;
+			} else {
 #ifdef IP_HDRINCL
-			int hincl = 1;
+				int hincl = 1;
 #endif
 		
-			s->esp_fd = socket(PF_INET, SOCK_RAW, IPPROTO_ESP);
-			if (s->esp_fd == -1) {
-				close_tunnel(s);
-				error(1, errno, "Couldn't open socket of ESP. Maybe something registered ESP already.\nPlease try '--natt-mode force-natt' or disable whatever is using ESP.\nsocket(PF_INET, SOCK_RAW, IPPROTO_ESP)");
-			}
+				s->esp_fd = socket(PF_INET, SOCK_RAW, IPPROTO_ESP);
+				if (s->esp_fd == -1) {
+					close_tunnel(s);
+					error(1, errno, "Couldn't open socket of ESP. Maybe something registered ESP already.\nPlease try '--natt-mode force-natt' or disable whatever is using ESP.\nsocket(PF_INET, SOCK_RAW, IPPROTO_ESP)");
+				}
+#ifdef FD_CLOEXEC
+				/* do not pass socket to vpnc-script, etc. */
+				fcntl(s->esp_fd, F_SETFD, FD_CLOEXEC);
+#endif
 #ifdef IP_HDRINCL
-			if (setsockopt(s->esp_fd, IPPROTO_IP, IP_HDRINCL, &hincl, sizeof(hincl)) == -1) {
-				close_tunnel(s);
-				error(1, errno, "setsockopt(esp_fd, IPPROTO_IP, IP_HDRINCL, 1)");
-			}
+				if (setsockopt(s->esp_fd, IPPROTO_IP, IP_HDRINCL, &hincl, sizeof(hincl)) == -1) {
+					close_tunnel(s);
+					error(1, errno, "setsockopt(esp_fd, IPPROTO_IP, IP_HDRINCL, 1)");
+				}
 #endif
+			}
 		}
 		
 		s->ipsec.rx.seq_id = s->ipsec.tx.seq_id = 1;
@@ -3224,9 +3230,14 @@
 			 */
 			/* FIXME: any cleanup needed??? */
 
-			free_isakmp_packet(r);
-			do_phase2_qm(s);
-			return;
+			if (rp->u.d.num_spi >= 1 && memcmp(rp->u.d.spi[0], &s->ipsec.tx.spi, 4) == 0) {
+				free_isakmp_packet(r);
+				do_phase2_qm(s);
+				return;
+			} else {
+				DEBUG(2, printf("got isakmp delete with bogus spi, ignoring...\n"));
+				continue;
+			}
 		}
 		/* skip ipsec-esp delete */
 		if (rp->u.d.protocol != ISAKMP_IPSEC_PROTO_ISAKMP) {
