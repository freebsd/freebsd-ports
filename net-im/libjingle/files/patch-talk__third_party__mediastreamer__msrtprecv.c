--- ./talk/third_party/mediastreamer/msrtprecv.c.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msrtprecv.c	Fri Apr 21 10:56:34 2006
@@ -70,6 +70,8 @@
 	memset(r->q_outputs,0,sizeof(MSFifo*)*MSRTPRECV_MAX_OUTPUTS);
 	r->rtpsession=NULL;
 	r->stream_started=0;
+	r->ignore=FALSE;
+	r->payload_expected=0;
 }
 
 void ms_rtp_recv_class_init(MSRtpRecvClass *klass)
@@ -120,7 +122,7 @@
 		gint got=0;
 		/* we are connected with queues (surely for video)*/
 		/* use the sync system time to compute a timestamp */
-		PayloadType *pt=rtp_profile_get_payload(r->rtpsession->profile,r->rtpsession->payload_type);
+		PayloadType *pt=rtp_profile_get_payload(r->rtpsession->profile,r->rtpsession->send_pt);
 		if (pt==NULL) {
 			ms_warning("ms_rtp_recv_process(): NULL RtpPayload- skipping.");
 			return;
@@ -134,10 +136,16 @@
 			/*g_message("Got packet with timestamp %u",clock);*/
 			got++;
 			r->stream_started=1;
-			mdata=mp->b_cont;
-			freeb(mp);
-			msg=msgb_2_ms_message(mdata);
-			ms_queue_put(qo,msg);
+			if (!r->ignore){
+				gboolean markbit=((rtp_header_t*)mp->b_rptr)->markbit;
+				mdata=mp->b_cont;
+				freeb(mp);
+				msg=msgb_2_ms_message(mdata);
+				msg->markbit=markbit;
+				ms_queue_put(qo,msg);
+			}else{
+				freemsg(mp);
+			}
 		}
 	}
 }
@@ -147,10 +155,24 @@
 	g_free(obj);
 }
 
+static void __payload_type_changed(RtpSession *session,MSRtpRecv *obj){
+	int pt_num=rtp_session_get_recv_payload_type(session);
+	PayloadType *pt=rtp_profile_get_payload(rtp_session_get_profile(session),pt_num);
+	if (pt==NULL){
+		/* sip phone should ignore payload types they don't understand */
+		g_warning("Ignoring payload type %i",pt_num);
+		obj->ignore=TRUE;
+	}else{
+		if (obj->ignore) g_warning("payload type is coming back to something known");
+		obj->ignore=FALSE;
+	}
+}
+
 RtpSession * ms_rtp_recv_set_session(MSRtpRecv *obj,RtpSession *session)
 {
 	RtpSession *old=obj->rtpsession;
 	obj->rtpsession=session;
+	rtp_session_signal_connect(session,"payload_type_changed",(RtpCallback)__payload_type_changed,(unsigned long)obj);
 	obj->prev_ts=0;
 	return old;
 }
