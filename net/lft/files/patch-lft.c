--- lft.c.orig	Wed Mar  5 16:16:09 2003
+++ lft.c	Wed Mar  5 16:16:21 2003
@@ -928,7 +928,7 @@
 	//	return; /* not for us */
 
 
-    if (noisy) printf ("ICMP %u\n", ntohl (tcp->th_seq));
+    if (noisy) printf ("ICMP %lu\n", ntohl (tcp->th_seq));
     recv_packet (ntohl (tcp->th_seq) , orig_ip->ip_src,
 		 (icmp->icmp_type == ICMP_TIMXCEED) ? -2 : icmp->icmp_code);
     break;
@@ -949,7 +949,7 @@
       if (noisy) printf (" ACK ");
     if (tcp->th_flags & TH_SYN)
       if (noisy) printf (" SYN ");
-    if (noisy) printf (" seq %u ack %u ", ntohl (tcp->th_seq), ntohl (tcp->th_ack));
+    if (noisy) printf (" seq %lu ack %lu ", ntohl (tcp->th_seq), ntohl (tcp->th_ack));
     if (noisy) printf ("from %s\n", inet_ntoa (ip->ip_src));
 
 	 //if (ntohl(tcp->th_ack) < seq_start || ntohl(tcp->th_ack) > seq_start + trace_packet_info_length + 1)
