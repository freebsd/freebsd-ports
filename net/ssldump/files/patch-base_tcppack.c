--- base/tcppack.c.orig	2002-09-09 21:02:58.000000000 +0000
+++ base/tcppack.c	2009-03-11 19:40:48.000000000 +0000
@@ -222,7 +222,6 @@
     int r,_status;
     tcp_seq seq,right_edge;
     segment _seg;
-    segment *seg,*nseg=0;
     long l;
 
     l=p->len - p->tcp->th_off * 4;
@@ -273,35 +272,39 @@
     if(SEQ_LT(stream->seq,seq)){
       /* Out of order segment */
       tcp_seq left_edge;
+      segment **ssn, *nseg=0;
 
-      for(seg=0;seg;seg=seg?seg->next:stream->oo_queue){
-	if(seg->next->s_seq > seq)
+      left_edge = seq;
+      for(ssn=&stream->oo_queue;*ssn;ssn=&(*ssn)->next){
+	if((*ssn)->s_seq > seq)
 	  break;
+        left_edge = (*ssn)->s_seq + (*ssn)->len;
       }
-
+      /*
+         if seg == 0
+           oo_queue is empty - place out of order segment into oo_queue
+         else
+           place out of order segment into oo_queue after seg
+       */
+         
       if(!(nseg=(segment *)calloc(sizeof(segment),1)))
 	ABORT(R_NO_MEMORY);
       if(r=packet_copy(p,&nseg->p))
 	ABORT(r);
       nseg->s_seq=seq;
-      
+
       /*Insert this segment into the reassembly queue*/
-      if(seg){
-	nseg->next=seg->next;
-	seg->next=nseg;
-      }
-      else{
-	nseg->next=stream->oo_queue;	
-	stream->oo_queue=nseg;
-      }
+      nseg->next = *ssn;
+      *ssn = nseg;
 
-      left_edge=seg?seg->s_seq:stream->seq;
       STRIM(left_edge,nseg);
     }
     else{
       /*First segment -- just thread the unallocated data on the
        list so we can pass to the analyzer*/
-      _seg.next=0;
+      segment _seg, *seg;
+
+      _seg.next=stream->oo_queue;
       _seg.p=p;
       _seg.s_seq=seq;
 
