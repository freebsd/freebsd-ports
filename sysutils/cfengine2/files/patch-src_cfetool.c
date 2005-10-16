--- src/cfetool.c.orig	Thu Oct  6 19:16:39 2005
+++ src/cfetool.c	Thu Oct  6 19:25:48 2005
@@ -2646,9 +2646,9 @@ void DoBatch(int dbtype)
   double val=0;
   float val1=0, val2=0, val3=0, val4=0, val5=0, val6=0, val7=0, val8=0, val9=0, val10=0;
   int i = 0, j = 0, n = 0, y = 0, k = 0, w = 0;
-  time_to_update = false;
   int timeint = -1;
   struct Average av;
+  time_to_update = false;
 
   Verbose("Batch mode\n");
 
