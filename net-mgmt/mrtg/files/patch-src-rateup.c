--- src/rateup.c~   2005-05-16 19:15:06.468444000 +0200
+++ src/rateup.c    2005-05-16 19:15:09.138421000 +0200
@@ -318,6 +318,7 @@
     }

   /* multiplicator for bits/bytes */
+  maxv = (long long) max (maxvi, maxvo);
   maxvi = maxvi < (long long) 0 ? -maxvi : maxvi;
   maxvo = maxvo < (long long) 0 ? -maxvo : maxvo;
   origmaxvi = maxvi;
@@ -328,7 +329,6 @@
       maxvi *= muli;
       maxvo *= muli;
     }
-  maxv = (long long) max (maxvi, maxvo);
   if (step > MONTH_SAMPLE)
     {
       type = 4;
