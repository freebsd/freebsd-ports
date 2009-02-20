--- ./src/rmonitor.c.orig	2001-07-20 18:31:10.000000000 +0300
+++ ./src/rmonitor.c	2009-02-20 11:24:12.000000000 +0200
@@ -294,7 +294,7 @@
 #define samples 2
   double lavg[samples];
   int    dbufs  = 0;
-  int    len;
+  long   len;
   int    maxf   = -1;
   int    maxp   = -1;
   int    memfre = 0;
