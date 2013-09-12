
$FreeBSD$

--- ehnt.h.orig
+++ ehnt.h
@@ -23,6 +23,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <time.h>
 #include <sys/socket.h>
 #include <sys/socketvar.h>
@@ -59,6 +60,7 @@
 
 struct ehnt_stats {
   double InBoundTotal, OutBoundTotal;
+  double InBoundTotalPkts, OutBoundTotalPkts;
   double *InBoundSrcAS, *InBoundDstAS, *OutBoundSrcAS, *OutBoundDstAS;
   double *InBoundProto, *OutBoundProto;
   double *InBoundSrcTcpPort, *InBoundDstTcpPort, 
@@ -93,7 +95,7 @@
 int ProcessFlow(struct flow_ver5_rec *, struct in_addr *, struct ehnt_struct *);
 int Init_ASN_Lookups(void);
 char * ASN_Lookup(int);
-char * prettybytes(int);
+char * prettybytes(unsigned);
 void DisplayReport(time_t, struct ehnt_data *);
 
 /* these EM_ defines are for the mode config variable */
