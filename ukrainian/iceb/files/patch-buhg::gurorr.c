--- buhg/gurorr.c.orig	Wed Oct  8 19:51:05 2003
+++ buhg/gurorr.c	Wed Oct  8 19:51:21 2003
@@ -69,9 +69,9 @@
 char            bros[100];
 char            str[300];
 FILE		*ff1;
-long            tmm;
-long            tmmn;
-long            tmmk;
+time_t            tmm;
+time_t            tmmn;
+time_t            tmmk;
 double          sd,sk,sdn,skn,dns,kns;
 double          sdgr,skgr,sdngr,skngr,dnsgr,knsgr;
 char            imaf[20],imaf2[20],imaf3[20];
