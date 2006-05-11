--- ./talk/third_party/mediastreamer/audiostream.c.orig	Thu Mar 16 18:43:07 2006
+++ ./talk/third_party/mediastreamer/audiostream.c	Fri Apr 21 10:56:34 2006
@@ -29,6 +29,8 @@
 
 #define MAX_RTP_SIZE	1500
 
+#define rtp_session_max_buf_size_set(session, bufsize) (rtp_session_set_recv_buf_size(session, bufsize))
+
 /* this code is not part of the library itself, it is part of the mediastream program */
 void audio_stream_free(AudioStream *stream)
 {
@@ -118,7 +120,8 @@
 	if (remport>0) rtp_session_set_remote_addr(rtpr,remip,remport);
 	rtp_session_set_scheduling_mode(rtpr,0);
 	rtp_session_set_blocking_mode(rtpr,0);
-	rtp_session_set_payload_type(rtpr,payload);
+	rtp_session_set_send_payload_type(rtpr,payload);
+	rtp_session_set_recv_payload_type(rtpr,payload);
 	rtp_session_set_jitter_compensation(rtpr,jitt_comp);
 	rtp_session_enable_adaptive_jitter_compensation(rtpr,TRUE);
 	/*rtp_session_signal_connect(rtpr,"timestamp_jump",(RtpCallback)on_timestamp_jump,NULL);*/
@@ -143,7 +146,8 @@
 	rtp_session_set_remote_addr(rtps,remip,remport);
 	rtp_session_set_scheduling_mode(rtps,0);
 	rtp_session_set_blocking_mode(rtps,0);
-	rtp_session_set_payload_type(rtps,payload);
+	rtp_session_set_send_payload_type(rtps,payload);
+	rtp_session_set_recv_payload_type(rtps,payload);
 	rtp_session_set_jitter_compensation(rtps,jitt_comp);
 	
 	rtpr=rtp_session_new(RTP_SESSION_RECVONLY);
@@ -156,9 +160,9 @@
 #endif
 	rtp_session_set_scheduling_mode(rtpr,0);
 	rtp_session_set_blocking_mode(rtpr,0);
-	rtp_session_set_payload_type(rtpr,payload);
+	rtp_session_set_send_payload_type(rtpr,payload);  
+	rtp_session_set_recv_payload_type(rtpr,payload);
 	rtp_session_set_jitter_compensation(rtpr,jitt_comp);
-	rtp_session_signal_connect(rtpr,"telephone-event",(RtpCallback)on_dtmf_received,NULL);
 	rtp_session_signal_connect(rtpr,"timestamp_jump",(RtpCallback)on_timestamp_jump,NULL);
 	*recv=rtpr;
 	*send=rtps;
@@ -179,8 +183,6 @@
 	rtp_session_signal_connect(rtpr,"telephone-event",(RtpCallback)on_dtmf_received,(gpointer)stream);
 	rtps=rtpr;
 	
-	stream->recv_session = rtpr;
-	stream->send_session = rtps;
 	stream->rtpsend=ms_rtp_send_new();
 	ms_rtp_send_set_session(MS_RTP_SEND(stream->rtpsend),rtps);
 	stream->rtprecv=ms_rtp_recv_new();
@@ -217,8 +219,8 @@
 	ms_filter_set_property(stream->decoder,MS_FILTER_PROPERTY_FREQ,&pt->clock_rate);
 	ms_filter_set_property(stream->decoder,MS_FILTER_PROPERTY_BITRATE,&pt->normal_bitrate);
 	
-	ms_filter_set_property(stream->encoder,MS_FILTER_PROPERTY_FMTP, (void*)pt->fmtp);
-	ms_filter_set_property(stream->decoder,MS_FILTER_PROPERTY_FMTP,(void*)pt->fmtp);
+	ms_filter_set_property(stream->encoder,MS_FILTER_PROPERTY_FMTP,(void*)pt->send_fmtp);
+	ms_filter_set_property(stream->decoder,MS_FILTER_PROPERTY_FMTP,(void*)pt->recv_fmtp);
 	/* create the synchronisation source */
 	stream->timer=ms_timer_new();
 	
@@ -340,4 +342,5 @@
 {
 	ms_rtp_send_dtmf(MS_RTP_SEND(stream->rtpsend), dtmf);
 	ms_oss_write_play_dtmf(MS_OSS_WRITE(stream->soundwrite),dtmf);
+	return 0;
 }
