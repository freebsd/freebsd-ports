--- src/cfetoolgraph.c.orig	Thu Oct  6 19:31:19 2005
+++ src/cfetoolgraph.c	Thu Oct  6 19:32:22 2005
@@ -542,6 +542,8 @@ void WriteGraphFiles(int dbtype)
 void WriteHistogram(int dbtype)
 {
   int numdays=0;
+  int position, day;
+  int weekly[CF_GRAINS];
   /* Finally, look at the histogram */
 
   printf("Writing histogram file now!\n");
@@ -554,8 +556,6 @@ void WriteHistogram(int dbtype)
     }
   }
 
-  int position, day;
-  int weekly[CF_GRAINS];
 
   switch(dbtype)
   {
