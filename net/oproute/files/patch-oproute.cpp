--- oproute.cpp.orig	Sat Mar  3 23:16:17 2001
+++ oproute.cpp	Sat Mar  3 23:18:11 2001
@@ -706,7 +706,7 @@
 	    udp = (struct udphdr *)(recvbuf + hlen1 + 8 +hlen2);
 	    if(hip->ip_p == IPPROTO_UDP)
 	      {
-		pHop->nPort = ntohs(udp->dest);
+		pHop->nPort = ntohs(udp->uh_dport);
 		pHop->sRouterIP = sock_ntop_host((sockaddr *)sa_recv, sa_len);
 		pHop->state = HOP_COMPLETED;
 		pHop->fLatency = GetLatencyFromTV(tvNow, tvTimeOfLastSend);
@@ -721,14 +721,14 @@
 	      {
 		if (icmp->icmp_code == ICMP_UNREACH_PORT) 
 		  {
-		    pHop->nPort = ntohs(udp->dest);
+		    pHop->nPort = ntohs(udp->uh_dport);
 		    pHop->sRouterIP = sock_ntop_host((sockaddr *)sa_recv, sa_len);
 		    pHop->state = HOP_ENDOFLINE;
 		    pHop->fLatency = GetLatencyFromTV(tvNow, tvTimeOfLastSend);
 		  }
 		else 
 		  {
-		    pHop->nPort = ntohs(udp->dest);
+		    pHop->nPort = ntohs(udp->uh_dport);
 		    pHop->sRouterIP = sock_ntop_host((sockaddr *)sa_recv, sa_len);
 		    pHop->state = HOP_FAILED;
 		  }
