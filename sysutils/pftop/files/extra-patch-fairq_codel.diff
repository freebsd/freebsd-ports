--- pftop.c.orig	2013-05-11 12:53:55.000000000 +0000
+++ pftop.c	2013-05-11 12:54:00.000000000 +0000
@@ -48,6 +48,8 @@
 #include <altq/altq_cbq.h>
 #include <altq/altq_priq.h>
 #include <altq/altq_hfsc.h>
+#include <altq/altq_fairq.h>
+#include <altq/altq_codel.h>
 #endif
 
 #include <ctype.h>
@@ -371,6 +373,8 @@
 	class_stats_t		cbq_stats;
 	struct priq_classstats	priq_stats;
 	struct hfsc_classstats	hfsc_stats;
+	struct fairq_classstats	fairq_stats;
+	struct codel_ifstats	codel_stats;
 };
 
 struct queue_stats {
@@ -1764,6 +1768,8 @@
 		return (-1);
 	}
 	num_queues = nr_queues = pa.nr;
+	if (pa.altq.scheduler == ALTQT_CODEL)
+		num_queues = 1;
 	for (nr = 0; nr < nr_queues; ++nr) {
 		pa.nr = nr;
 		if (ioctl(pf_dev, DIOCGETALTQ, &pa)) {
@@ -1772,10 +1778,10 @@
 			return (-1);
 		}
 #ifdef PFALTQ_FLAG_IF_REMOVED
-		if (pa.altq.qid > 0 &&
+		if ((pa.altq.qid > 0 || pa.altq.scheduler == ALTQT_CODEL) &&
 		    !(pa.altq.local_flags & PFALTQ_FLAG_IF_REMOVED)) {
 #else
-		if (pa.altq.qid > 0) {
+		if (pa.altq.qid > 0  || pa.altq.scheduler == ALTQT_CODEL) {
 #endif
 			pq.nr = nr;
 			pq.ticket = pa.ticket;
@@ -1928,11 +1934,14 @@
 	tb_start();
 	for (d = 0; d < node->depth; d++)
 		tbprintf(" ");
-	tbprintf(node->altq.qname);
+	if (node->altq.qname[0] != '\0')
+		tbprintf(node->altq.qname);
+	else
+		tbprintf("root");
 	print_fld_tb(FLD_QUEUE);
 
 	if (node->altq.scheduler == ALTQT_CBQ ||
-	    node->altq.scheduler == ALTQT_HFSC
+	    node->altq.scheduler == ALTQT_HFSC || node->altq.scheduler == ALTQT_FAIRQ || node->altq.scheduler == ALTQT_CODEL
 		)
 		print_fld_bw(FLD_BANDW, (double)node->altq.bandwidth);
 	
@@ -2003,6 +2012,42 @@
 					node->qstats_last.data.hfsc_stats.xmit_cnt.bytes, interval);
 		}
 		break;
+       case ALTQT_FAIRQ:
+               print_fld_str(FLD_SCHED, "fairq");
+               print_fld_size(FLD_PKTS,
+                               node->qstats.data.fairq_stats.xmit_cnt.packets);
+               print_fld_size(FLD_BYTES,
+                               node->qstats.data.fairq_stats.xmit_cnt.bytes);
+               print_fld_size(FLD_DROPP,
+                               node->qstats.data.fairq_stats.drop_cnt.packets);
+               print_fld_size(FLD_DROPB,
+                               node->qstats.data.fairq_stats.drop_cnt.bytes);
+               print_fld_size(FLD_QLEN, node->qstats.data.fairq_stats.qlength);
+               if (interval > 0) {
+                       pps = calc_pps(node->qstats.data.fairq_stats.xmit_cnt.packets,
+                                       node->qstats_last.data.fairq_stats.xmit_cnt.packets, interval);
+                       bps = calc_rate(node->qstats.data.fairq_stats.xmit_cnt.bytes,
+                                       node->qstats_last.data.fairq_stats.xmit_cnt.bytes, interval);
+               }
+               break;
+       case ALTQT_CODEL:
+               print_fld_str(FLD_SCHED, "codel");
+               print_fld_size(FLD_PKTS,
+                               node->qstats.data.codel_stats.cl_xmitcnt.packets);
+               print_fld_size(FLD_BYTES,
+                               node->qstats.data.codel_stats.cl_xmitcnt.bytes);
+               print_fld_size(FLD_DROPP,
+                               node->qstats.data.codel_stats.cl_dropcnt.packets);
+               print_fld_size(FLD_DROPB,
+                               node->qstats.data.codel_stats.cl_dropcnt.bytes);
+               print_fld_size(FLD_QLEN, node->qstats.data.codel_stats.qlength);
+               if (interval > 0) {
+                       pps = calc_pps(node->qstats.data.codel_stats.cl_xmitcnt.packets,
+                                       node->qstats_last.data.codel_stats.cl_xmitcnt.packets, interval);
+                       bps = calc_rate(node->qstats.data.codel_stats.cl_xmitcnt.bytes,
+                                       node->qstats_last.data.codel_stats.cl_xmitcnt.bytes, interval);
+               }
+               break;
 	}
 
 	/* if (node->altq.scheduler != ALTQT_HFSC && interval > 0) { */
