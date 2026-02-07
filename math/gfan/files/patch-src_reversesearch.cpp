--- src/reversesearch.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/reversesearch.cpp
@@ -65,7 +65,7 @@ int ReverseSearch::treeSize(PolynomialSet &groebnerBas
     static int n;
     n++;
     if(!(n%10))
-      log2 fprintf(Stderr,"%i %i\n",n,depth);
+      gfan_log2 fprintf(Stderr,"%i %i\n",n,depth);
   }
 
   int s=1;
@@ -144,17 +144,17 @@ int ReverseSearch::treeSize(PolynomialSet &groebnerBas
 
 PolynomialSet ReverseSearch::findRoot(PolynomialSet groebnerBasis)
 {
-  log2 fprintf(Stderr,"Computing root\n");
-  log2 buchberger(&groebnerBasis,termOrder);
+  gfan_log2 fprintf(Stderr,"Computing root\n");
+  gfan_log2 buchberger(&groebnerBasis,termOrder);
 
   IntegerVector edge;
   while(computeSearchEdge(groebnerBasis,&edge))
     {
-      log2 AsciiPrinter(Stderr).printVector(edge);
+      gfan_log2 AsciiPrinter(Stderr).printVector(edge);
       groebnerBasis=flip(groebnerBasis,edge);
     }
 
-  log2 fprintf(Stderr,"Done computing root\n");
+  gfan_log2 fprintf(Stderr,"Done computing root\n");
   return groebnerBasis;
 }
 
