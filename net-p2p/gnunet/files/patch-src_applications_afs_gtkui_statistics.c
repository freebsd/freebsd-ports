--- src/applications/afs/gtkui/statistics.c.orig	Fri May 21 09:34:00 2004
+++ src/applications/afs/gtkui/statistics.c	Fri May 21 09:34:23 2004
@@ -178,14 +178,14 @@
 				 gfloat ** data) {
   long long val;
   char * cmh;
-  long long cval;
+  long cval;
 
   cmh = getConfigurationOptionValue(sock,
 				    "gnunetd",
 				    "connection-max-hosts");
   if (cmh == NULL)
     return SYSERR;
-  cval = atoll(cmh);
+  cval = atol(cmh);
   FREE(cmh);
   if (OK != getStatValue(&val,
 			 NULL,
@@ -291,7 +291,7 @@
 					  "MAXNETDOWNBPSTOTAL");
   if (available == NULL)
     return SYSERR; 
-  band = atoll(available) * dtime / cronSECONDS;
+  band = atol(available) * dtime / cronSECONDS;
   FREE(available);
   total -= ltotal;
   noise -= lnoise;
@@ -395,7 +395,7 @@
 					  "MAXNETUPBPSTOTAL");
   if (available == NULL)
     return SYSERR;
-  band = atoll(available) * dtime / cronSECONDS;
+  band = atol(available) * dtime / cronSECONDS;
   FREE(available);
   total -= ltotal;
   noise -= lnoise;
