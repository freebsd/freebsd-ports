--- config.c.orig	Thu Apr 14 16:07:26 2005
+++ config.c	Thu Apr 14 14:55:34 2005
@@ -838,7 +838,7 @@
 		    IP_PROTO_TCP, src.addr_ip, dst.addr_ip);
 		ip_checksum(pkt, iplen);
 
-		honeyd_recv_cb(&inter, &pkthdr, pkt);
+		honeyd_recv_cb((u_char *)&inter, &pkthdr, pkt);
 	}
 	gettimeofday(&tv_end, NULL);
 	timersub(&tv_end, &tv_start, &tv_end);
