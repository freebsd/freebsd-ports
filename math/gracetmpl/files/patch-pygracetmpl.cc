--- python/src/pygracetmpl.cc.orig	Mon Aug 16 18:25:45 2004
+++ python/src/pygracetmpl.cc	Mon Aug 16 18:31:35 2004
@@ -179,7 +179,7 @@
   int rows = dataArray->dimensions[1];
   if(cols > 4)
     cols = 4;
-  double **data = new (double *)[cols];
+  double **data = new double *[cols];
   for(int c = 0; c < cols; ++c){
     data[c] = new double[rows];
     for(int r = 0; r < rows; ++r)
