--- talk/third_party/mediastreamer/msrtprecv.c.orig	Wed Feb 22 16:43:03 2006
+++ talk/third_party/mediastreamer/msrtprecv.c	Wed Feb 22 16:45:47 2006
@@ -120,7 +120,7 @@
 		gint got=0;
 		/* we are connected with queues (surely for video)*/
 		/* use the sync system time to compute a timestamp */
-		PayloadType *pt=rtp_profile_get_payload(r->rtpsession->profile,r->rtpsession->payload_type);
+		PayloadType *pt=rtp_profile_get_payload(r->rtpsession->profile,r->rtpsession->recv_pt);
 		if (pt==NULL) {
 			ms_warning("ms_rtp_recv_process(): NULL RtpPayload- skipping.");
 			return;
