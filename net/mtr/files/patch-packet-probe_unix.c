--- packet/probe_unix.c.orig	2019-08-03 08:31:26 UTC
+++ packet/probe_unix.c
@@ -795,7 +795,6 @@ void receive_replies_from_recv_socket(
                 memcpy(&remote_addr, SO_EE_OFFENDER(ee), sizeof(remote_addr));
             }
         }
-#endif
 
 #ifdef SO_PROTOCOL
         if (icmp_connrefused_received) {
@@ -815,11 +814,14 @@ void receive_replies_from_recv_socket(
                     packet, packet_length, &timestamp);
         } else {
 #endif
+#endif
             /* ICMP packets received from raw socket */
             handle_received_packet(net_state, &remote_addr, packet,
                                    packet_length, &timestamp);
 #ifdef SO_PROTOCOL
+#ifdef HAVE_LINUX_ERRQUEUE_H
         }
+#endif
 #endif
     }
 }
