
$FreeBSD$

--- ehnt_display.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_display.c	Wed Jun 23 14:35:08 2004
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
