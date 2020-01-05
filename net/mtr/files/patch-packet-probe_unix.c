--- packet/probe_unix.c.orig	2019-08-03 08:31:26 UTC
+++ packet/probe_unix.c
@@ -798,6 +798,7 @@ void receive_replies_from_recv_socket(
 #endif
 
 #ifdef SO_PROTOCOL
+#ifdef HAVE_LINUX_ERRQUEUE_H
         if (icmp_connrefused_received) {
             /* using ICMP type ICMP_ECHOREPLY is not a bug, it is an
                indication of successfully reaching dst host.
@@ -815,11 +816,14 @@ void receive_replies_from_recv_socket(
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
