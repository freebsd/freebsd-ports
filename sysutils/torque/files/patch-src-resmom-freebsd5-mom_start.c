--- src/resmom/freebsd5/mom_start.c.orig	2011-06-24 13:40:31.000000000 -0500
+++ src/resmom/freebsd5/mom_start.c	2011-06-24 13:41:15.000000000 -0500
@@ -214,6 +214,7 @@
   task  *ptask = 0;
   int  statloc;
   unsigned int momport = 0;
+  extern unsigned int pbs_rm_port;
 
   if (LOGLEVEL >= 7)
     {
