
$FreeBSD$

--- ehnt.h.orig	Thu Oct  4 22:18:29 2001
+++ ehnt.h	Wed Jun 23 14:35:08 2004
@@ -59,6 +59,7 @@
 
 struct ehnt_stats {
   double InBoundTotal, OutBoundTotal;
+  double InBoundTotalPkts, OutBoundTotalPkts;
   double *InBoundSrcAS, *InBoundDstAS, *OutBoundSrcAS, *OutBoundDstAS;
   double *InBoundProto, *OutBoundProto;
   double *InBoundSrcTcpPort, *InBoundDstTcpPort, 
@@ -93,7 +94,7 @@
 int ProcessFlow(struct flow_ver5_rec *, struct in_addr *, struct ehnt_struct *);
 int Init_ASN_Lookups(void);
 char * ASN_Lookup(int);
-char * prettybytes(int);
+char * prettybytes(unsigned);
 void DisplayReport(time_t, struct ehnt_data *);
 
 /* these EM_ defines are for the mode config variable */
