--- tcplog_dumper.c.orig	2026-10-15 07:54:11 UTC
+++ tcplog_dumper.c
@@ -987,8 +987,8 @@ pcap_tcpbuf_opt(struct tcp_log_buffer *tlb, bool in_cb
 		    tlb->tlb_stackinfo.u_bbr.bbr_substate;
 		tlb_le->tlb_stackinfo.u_bbr.inhpts =
 		    tlb->tlb_stackinfo.u_bbr.inhpts;
-		tlb_le->tlb_stackinfo.u_bbr.ininput =
-		    tlb->tlb_stackinfo.u_bbr.ininput;
+		tlb_le->tlb_stackinfo.u_bbr.__spare =
+		    tlb->tlb_stackinfo.u_bbr.__spare;
 		tlb_le->tlb_stackinfo.u_bbr.use_lt_bw =
 		    tlb->tlb_stackinfo.u_bbr.use_lt_bw;
 		tlb_le->tlb_stackinfo.u_bbr.flex8 =
