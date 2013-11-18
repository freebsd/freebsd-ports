--- drivers/dahdi/wctc4xxp/base.c.orig	2013-11-18 19:15:33.000000000 +0700
+++ drivers/dahdi/wctc4xxp/base.c	2013-11-18 19:15:48.000000000 +0700
@@ -2423,8 +2423,8 @@
 
 	if (unlikely(count > SFRAME_SIZE - sizeof(struct rtp_packet))) {
 		DTE_DEBUG(DTE_DEBUG_GENERAL,
-		   "Cannot transcode packet of %Zu bytes. This exceeds the " \
-		   "maximum size of %Zu bytes.\n", count,
+		   "Cannot transcode packet of %zu bytes. This exceeds the " \
+		   "maximum size of %zu bytes.\n", count,
 		   SFRAME_SIZE - sizeof(struct rtp_packet));
 		return -EINVAL;
 	}
@@ -2434,7 +2434,7 @@
 		    (G723_SID_BYTES != count)) {
 			DTE_DEBUG(DTE_DEBUG_GENERAL,
 			   "Trying to transcode packet into G723 format " \
-			   "that is %Zu bytes instead of the expected " \
+			   "that is %zu bytes instead of the expected " \
 			   "%d/%d/%d bytes.\n", count, G723_5K_BYTES,
 			   G723_6K_BYTES, G723_SID_BYTES);
 			return -EINVAL;
@@ -2465,7 +2465,7 @@
 	cpvt->seqno += 1;
 
 	DTE_DEBUG(DTE_DEBUG_RTP_TX,
-	    "Sending packet of %Zu byte on channel (%p).\n", count, dtc);
+	    "Sending packet of %zu byte on channel (%p).\n", count, dtc);
 
 	atomic_inc(&cpvt->stats.packets_sent);
 	wctc4xxp_transmit_cmd(wc, cmd);
