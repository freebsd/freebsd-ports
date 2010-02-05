--- libdieharder/countx.c.orig	2009-12-27 13:35:32.000000000 -0500
+++ libdieharder/countx.c	2009-12-27 13:36:18.000000000 -0500
@@ -219,6 +219,7 @@
   for (i=0; i<=MAXBITS; ++i) {
     if (ftab[i] > BUCKETS) {
       fprintf(stderr, "ftab[%lu]=%lu needs a bigger LOGBUCKETS\n", i, ftab[i]);
+      free(data);
       return 1;
     }
   }
