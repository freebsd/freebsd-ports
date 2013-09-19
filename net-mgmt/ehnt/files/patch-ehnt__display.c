
$FreeBSD$

--- ehnt_display.c.orig
+++ ehnt_display.c
@@ -22,10 +22,10 @@
 #include "config.h"
 #include "ehnt.h"
 
-double ShowTopAS (double a[],char t[], int ,double);
-double ShowTopProto (double a[], char t[], int ,double);
-double ShowTopUdpPort (double a[],char t[], int, double);
-double ShowTopTcpPort (double a[],char t[], int, double);
+void ShowTopAS (double a[],char t[], int ,double);
+void ShowTopProto (double a[], char t[], int ,double);
+void ShowTopUdpPort (double a[],char t[], int, double);
+void ShowTopTcpPort (double a[],char t[], int, double);
 double GetTop (double a[], char t[]);
 int ShowValue(char *, int, double, int, double);
 int ShowReport(struct ehnt_stats *, struct ehnt_struct *);
@@ -110,7 +110,9 @@
   ShowReportTimeHeader(stats);
 
   if ( ! report_inout ) {
-    printf (" Total %10.0fkbits/s\n",stats->InBoundTotal*8/((interval)*1024));
+    printf (" Total %10.0fkbits/s, %10.0fkpps\n",
+	stats->InBoundTotal*8/((interval)*1024),
+	stats->InBoundTotalPkts/((interval)*1024));
     if ( e_cfg->topmode != ETM_PROTO ) {
       printf ("Rank|-------------Source----------------| |---------------Dest----------------|\n");
     }
@@ -151,8 +153,9 @@
       printf ("Rank|-------------Source----------------| |---------------Dest----------------|\n");
     }
     printf("%s",header);
-    printf ("                          O   U   T   B   O   U   N   D  (total %.0fkbits/s)\n",
-	    stats->OutBoundTotal*8/((interval)*1024));
+    printf ("                          O   U   T   B   O   U   N   D  (total %.0fkbits/s, %.0fkpps)\n",
+	    stats->OutBoundTotal*8/((interval)*1024),
+	    stats->OutBoundTotalPkts/((interval)*1024));
 
     for (i=1; i<= (int)(e_cfg->screenlength - headersize)/2 + 1; i++) {
       printf("%2d:",i);
@@ -183,8 +186,9 @@
       }
       printf("\n");
     }
-    printf ("                            I   N   B   O   U   N   D    (total %.0fkbits/s)\n",
-	    stats->InBoundTotal*8/((interval)*1000));
+    printf ("                            I   N   B   O   U   N   D    (total %.0fkbits/s, %.0fkpps)\n",
+	    stats->InBoundTotal*8/((interval)*1024),
+	    stats->InBoundTotalPkts/((interval)*1024));
     for (i=1; i<= (int)(e_cfg->screenlength - headersize)/2; i++) {
       printf("%2d:",i);
       switch (e_cfg->topmode) {
@@ -246,7 +250,7 @@
 
 static char str[100];
 
-char * prettybytes(int bytes) {
+char * prettybytes(unsigned bytes) {
   
   if (bytes < 1024) sprintf(str,"%4d", bytes);
   else if (bytes < (1024*1024)) sprintf(str,"%4dK",(bytes/1024));
@@ -258,7 +262,7 @@
  return str;
 }
 
-double ShowTopAS (double a[],char t[], int interval, double total) {
+void ShowTopAS (double a[],char t[], int interval, double total) {
   int i=-1,maxi=0;
   struct protoent *p;
 
@@ -269,7 +273,7 @@
   ShowValue(ASN_Lookup(maxi),maxi,a[maxi],interval,total);
 }
 
-double ShowTopProto (double a[],char t[], int interval, double total) {
+void ShowTopProto (double a[],char t[], int interval, double total) {
   int i=-1,maxi=0;
   struct protoent *p;
 
@@ -285,7 +289,7 @@
   }
 }
 
-double ShowTopTcpPort (double a[],char t[], int interval, double total) {
+void ShowTopTcpPort (double a[],char t[], int interval, double total) {
   int i=-1,maxi=0;
   struct servent *s;
 
@@ -301,7 +305,7 @@
   }
 }
 
-double ShowTopUdpPort (double a[],char t[], int interval, double total) {
+void ShowTopUdpPort (double a[],char t[], int interval, double total) {
   int i=-1,maxi=0;
   struct servent *s;
 
