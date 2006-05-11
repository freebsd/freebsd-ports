--- ./talk/third_party/mediastreamer/msrtpsend.c.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msrtpsend.c	Fri Apr 21 10:56:34 2006
@@ -85,7 +85,7 @@
 {
 	guint32 clockts;
 	/* use the sync system time to compute a timestamp */
-	PayloadType *pt=rtp_profile_get_payload(r->rtpsession->profile,r->rtpsession->payload_type);
+	PayloadType *pt=rtp_profile_get_payload(r->rtpsession->profile,r->rtpsession->send_pt);
 	g_return_val_if_fail(pt!=NULL,0);
 	clockts=(guint32)(((double)synctime * (double)pt->clock_rate)/1000.0);
 	ms_trace("ms_rtp_send_process: sync->time=%i clock=%i",synctime,clockts);
@@ -138,8 +138,9 @@
 		while ( (msg=ms_queue_get(qi))!=NULL){
 			ts=get_new_timestamp(r,synctime);
 			if (!skip) {
-				/*g_message("Sending packet with ts=%u",ts);*/
-				rtp_session_send_with_ts(r->rtpsession,msg->data,msg->size,ts);
+				mblk_t *packet=rtp_session_create_packet_with_data(r->rtpsession,msg->data,msg->size,NULL);
+				rtp_set_markbit(packet,msg->markbit);
+				rtp_session_sendm_with_ts(r->rtpsession,packet,ts);
 				
 			}
 			ms_message_destroy(msg);
