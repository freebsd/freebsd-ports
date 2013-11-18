--- freebsd/drivers/dahdi/wctc4xxp/base.c.orig	2013-10-31 18:14:10.000000000 +0700
+++ freebsd/drivers/dahdi/wctc4xxp/base.c	2013-10-31 18:23:01.000000000 +0700
@@ -2456,9 +2456,9 @@
 
 	if (unlikely(count > SFRAME_SIZE - sizeof(struct rtp_packet))) {
 		DTE_DEBUG(DTE_DEBUG_GENERAL,
-		   "Cannot transcode packet of %Zu bytes. This exceeds the " \
-		   "maximum size of %Zu bytes.\n", count,
+		   "Cannot transcode packet of %zu bytes. This exceeds the " \
+		   "maximum size of %zu bytes.\n", count,
		   SFRAME_SIZE - sizeof(struct rtp_packet));
 		return -EINVAL;
 	}
 
@@ -2466,8 +2466,8 @@
 		if ((G723_5K_BYTES != count) && (G723_6K_BYTES != count)) {
 			DTE_DEBUG(DTE_DEBUG_GENERAL,
 			   "Trying to transcode packet into G723 format " \
-			   "that is %Zu bytes instead of the expected " \
+			   "that is %zu bytes instead of the expected " \
			   "%d/%d bytes.\n", count, G723_5K_BYTES,
 			   G723_6K_BYTES);
 			return -EINVAL;
 		}
@@ -2496,7 +2496,7 @@
 	cpvt->seqno += 1;
 
 	DTE_DEBUG(DTE_DEBUG_RTP_TX,
-	    "Sending packet of %Zu byte on channel (%p).\n", count, dtc);
+	    "Sending packet of %zu byte on channel (%p).\n", count, dtc);
 
 	atomic_inc(&cpvt->stats.packets_sent);
 	wctc4xxp_transmit_cmd(wc, cmd);
@@ -3355,10 +3355,6 @@
 		complicated = temp;
 	}
 
-	DTE_DEBUG(DTE_DEBUG_CHANNEL_SETUP,
-	   "DTE is using the following channels encoder_channel: " \
-	   "%d decoder_channel: %d\n", encoder_channel, decoder_channel);
-
 	BUG_ON(encoder_timeslot/2 >= wc->numchannels);
 	BUG_ON(decoder_timeslot/2 >= wc->numchannels);
 	encoder_pvt = wc->uencode->channels[encoder_timeslot/2].pvt;
@@ -3377,6 +3373,10 @@
 		&decoder_channel))
 		goto error_exit;
 
+	DTE_DEBUG(DTE_DEBUG_CHANNEL_SETUP,
+	   "DTE is using the following channels encoder_channel: " \
+	   "%d decoder_channel: %d\n", encoder_channel, decoder_channel);
+
 	length = (DTE_FORMAT_G729A == complicated) ? G729_LENGTH :
 		(DTE_FORMAT_G723_1 == complicated) ? G723_LENGTH : 0;
 
