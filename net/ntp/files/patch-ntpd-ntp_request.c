--- ntpd/ntp_request.c.orig	2011-11-30 18:55:17.000000000 -0800
+++ ntpd/ntp_request.c	2014-10-06 17:07:02.570303970 -0700
@@ -1956,7 +1956,6 @@
 	    printf("wants monitor 0 list\n");
 #endif
 	if (!mon_enabled) {
-		req_ack(srcadr, inter, inpkt, INFO_ERR_NODATA);
 		return;
 	}
 	im = (struct info_monitor *)prepare_pkt(srcadr, inter, inpkt,
@@ -2002,7 +2001,6 @@
 	extern int mon_enabled;
 
 	if (!mon_enabled) {
-		req_ack(srcadr, inter, inpkt, INFO_ERR_NODATA);
 		return;
 	}
 	im = (struct info_monitor_1 *)prepare_pkt(srcadr, inter, inpkt,
