
$FreeBSD$

--- ehnt_processflow.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_processflow.c	Wed Jun 23 14:35:08 2004
@@ -81,6 +81,8 @@
 	/* copy current stats to old stats */
 	old_stats->InBoundTotal=stats->InBoundTotal;
 	old_stats->OutBoundTotal=stats->OutBoundTotal;
+	old_stats->InBoundTotalPkts=stats->InBoundTotalPkts;
+	old_stats->OutBoundTotalPkts=stats->OutBoundTotalPkts;
 
 	old_stats->InBoundSrcAS=stats->InBoundSrcAS;
 	old_stats->InBoundDstAS=stats->InBoundDstAS;
@@ -126,6 +128,7 @@
 	if (e_flt->intnum) { 
 	  if (rec->output_index == e_flt->intnum) {
 	    stats->OutBoundTotal+=rec->dOctets;
+	    stats->OutBoundTotalPkts+=rec->dPkts;
 	    stats->OutBoundSrcAS[rec->src_as]+=rec->dOctets;
 	    stats->OutBoundDstAS[rec->dst_as]+=rec->dOctets;
 	    stats->OutBoundProto[rec->prot]+=rec->dOctets;
@@ -142,6 +145,7 @@
 	   we just put everthing in the InBound tables:  */
 	if ( (! e_flt->intnum) || (rec->input_index == e_flt->intnum) ) {
 	  stats->InBoundTotal+=rec->dOctets;
+	  stats->InBoundTotalPkts+=rec->dPkts;
 	  stats->InBoundSrcAS[rec->src_as]+=rec->dOctets;
 	  stats->InBoundDstAS[rec->dst_as]+=rec->dOctets;
 	  stats->InBoundProto[rec->prot]+=rec->dOctets;
@@ -218,7 +222,7 @@
 	dstip.s_addr=rec->dstaddr;
 	nexthop.s_addr=rec->nexthop;
 
-	printf("%.0f:%s",local_flowcount,routeraddr_string);
+	printf("%.0f:%s:",local_flowcount,routeraddr_string);
 	printf("%d:%s:%d:",
 	       rec->input_index,
 	       inet_ntoa(srcip),
@@ -228,7 +232,7 @@
 	       inet_ntoa(dstip),
 	       rec->dstport);
 	
-	printf("%d:%d:%d:",rec->dOctets,rec->dPkts,rec->prot);
+	printf("%u:%d:%d:",rec->dOctets,rec->dPkts,rec->prot);
 	printf("%d:%d\n",rec->src_as,rec->dst_as);
 
 	if (e_flt->big) {
@@ -289,6 +293,8 @@
 
   stats->InBoundTotal=0;
   stats->OutBoundTotal=0;
+  stats->InBoundTotalPkts=0;
+  stats->OutBoundTotalPkts=0;
 }
 
 int FreeStats (struct ehnt_stats *stats) {
