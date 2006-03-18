--- oRTP/src/rtpparse.c.orig	Wed Feb  1 01:06:16 2006
+++ oRTP/src/rtpparse.c	Sat Mar 11 01:12:41 2006
@@ -70,6 +70,7 @@
 	int msgsize;
 	RtpStream *rtpstream=&session->rtp;
 	rtp_stats_t *stats=&rtpstream->stats;
+	poly32_t *extseq;
 	
 	return_if_fail(mp!=NULL);
 	
@@ -120,7 +121,7 @@
 	}else session->recv_ssrc=rtp->ssrc;
 	
 	/* update some statistics */
-	poly32_t *extseq=(poly32_t*)&rtpstream->hwrcv_extseq;
+	extseq=(poly32_t*)&rtpstream->hwrcv_extseq;
 	if (rtp->seq_number>extseq->split.lo){
 		extseq->split.lo=rtp->seq_number;
 	}else if (rtp->seq_number<200 && extseq->split.lo>((1<<16) - 200)){
