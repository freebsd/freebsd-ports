--- talk/third_party/mediastreamer/msrtpsend.c.orig	Wed Feb 22 16:47:20 2006
+++ talk/third_party/mediastreamer/msrtpsend.c	Wed Feb 22 16:47:53 2006
@@ -85,7 +85,7 @@
 {
 	guint32 clockts;
 	/* use the sync system time to compute a timestamp */
-	PayloadType *pt=rtp_profile_get_payload(r->rtpsession->profile,r->rtpsession->payload_type);
+	PayloadType *pt=rtp_profile_get_payload(r->rtpsession->profile,r->rtpsession->send_pt);
 	g_return_val_if_fail(pt!=NULL,0);
 	clockts=(guint32)(((double)synctime * (double)pt->clock_rate)/1000.0);
 	ms_trace("ms_rtp_send_process: sync->time=%i clock=%i",synctime,clockts);
