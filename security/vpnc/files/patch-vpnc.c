--- vpnc.c.orig	2008-11-19 20:55:51 UTC
+++ vpnc.c
@@ -1160,8 +1160,11 @@ static void lifetime_ike_process(struct sa_block *s, s
 		value = a->next->u.attr_16;
 	else if (a->next->af == isakmp_attr_lots && a->next->u.lots.length == 4)
 		value = ntohl(*((uint32_t *) a->next->u.lots.data));
-	else
-		assert(0);
+	else {
+		DEBUG(2, printf("got unknown ike lifetime attributes af %d len %d\n",
+					a->next->af, a->next->u.lots.length));
+		return;
+	}
 	
 	DEBUG(2, printf("got ike lifetime attributes: %d %s\n", value,
 		(a->u.attr_16 == IKE_LIFE_TYPE_SECONDS) ? "seconds" : "kilobyte"));
@@ -1578,6 +1581,19 @@ static void do_phase1_am(const char *key_id, const cha
 						seen_natd_them = 1;
 				}
 				break;
+			case ISAKMP_PAYLOAD_N:
+				if (rp->u.n.type == ISAKMP_N_IPSEC_RESPONDER_LIFETIME) {
+					if (rp->u.n.protocol == ISAKMP_IPSEC_PROTO_ISAKMP)
+						lifetime_ike_process(s, rp->u.n.attributes);
+					else if (rp->u.n.protocol == ISAKMP_IPSEC_PROTO_IPSEC_ESP)
+						lifetime_ipsec_process(s, rp->u.n.attributes);
+					else
+						DEBUG(2, printf("got unknown lifetime notice, ignoring..\n"));
+				} else {
+					DEBUG(1, printf("rejecting ISAKMP_PAYLOAD_N, type is not lifetime\n"));
+					reject = ISAKMP_N_INVALID_PAYLOAD_TYPE;
+				}
+				break;
 			default:
 				DEBUG(1, printf("rejecting invalid payload type %d\n", rp->type));
 				reject = ISAKMP_N_INVALID_PAYLOAD_TYPE;
@@ -2861,28 +2877,34 @@ static void do_phase2_qm(struct sa_block *s)
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
@@ -3224,9 +3246,14 @@ void process_late_ike(struct sa_block *s, uint8_t *r_p
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
