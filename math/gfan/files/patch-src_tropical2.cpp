--- src/tropical2.cpp.orig	2017-09-28 13:40:06 UTC
+++ src/tropical2.cpp
@@ -287,7 +287,7 @@ PolynomialSet initialForms(PolynomialSet const &groebn
 PolyhedralFan tropicalPrincipalIntersection(int n, PolynomialSet const &g, int linealitySpaceDimension)
 {
   //return tropicalHyperSurfaceIntersection(n, g);////////////////////////////////////////
-  log2 fprintf(Stderr,"Intersecting\n");
+  gfan_log2 fprintf(Stderr,"Intersecting\n");
   log3 AsciiPrinter(Stderr).printPolynomialSet(g);
 
   TimerScope ts(&tropicalPrincipalIntersectionTimer);
@@ -297,7 +297,7 @@ PolyhedralFan tropicalPrincipalIntersection(int n, Pol
     {
       ret=refinement(ret,PolyhedralFan::bergmanOfPrincipalIdeal(*i),linealitySpaceDimension,true);
     }
-  log2 fprintf(Stderr,"Done intersecting\n");
+  gfan_log2 fprintf(Stderr,"Done intersecting\n");
   return ret;
 }
 
@@ -308,12 +308,12 @@ static PolynomialSet checkList(IntegerVectorList const
   for(IntegerVectorList::const_iterator i=l.begin();i!=l.end();i++)
     {
       WeightReverseLexicographicTermOrder t(*i);
-      log2 fprintf(Stderr,"Computing Gr\"obner basis with respect to:");
-      log2 AsciiPrinter(Stderr).printVector(*i);
-      log2 fprintf(Stderr,"\n");
+      gfan_log2 fprintf(Stderr,"Computing Gr\"obner basis with respect to:");
+      gfan_log2 AsciiPrinter(Stderr).printVector(*i);
+      gfan_log2 fprintf(Stderr,"\n");
       PolynomialSet h2=groebnerBasis;
       buchberger(&h2,t);
-      log2 fprintf(Stderr,"Done computing Gr\"obner basis.\n");
+      gfan_log2 fprintf(Stderr,"Done computing Gr\"obner basis.\n");
 
       log3 AsciiPrinter(Stderr).printPolynomialSet(h2);
       PolynomialSet wall=initialFormsAssumeMarked(h2,*i);
@@ -459,14 +459,14 @@ PolynomialSet guessInitialIdealWithoutMonomial(Polynom
   #endif
 
   {
-    //log2
+    //gfan_log2
     fprintf(Stderr,"Computing extreme rays.\n");
     //IntegerVectorList a;
     PolyhedralCone p=coneFromMarkedBasis(groebnerBasis);
     //PolyhedralCone p=PolyhedralCone(wallInequalities(groebnerBasis),a);
     IntegerVectorList extreme=p.extremeRays();
-    log2 fprintf(Stderr,"Extreme rays of Groebner cone:\n");
-    log2 AsciiPrinter(Stderr).printVectorList(extreme);
+    gfan_log2 fprintf(Stderr,"Extreme rays of Groebner cone:\n");
+    gfan_log2 AsciiPrinter(Stderr).printVectorList(extreme);
 
     bool result;
     PolynomialSet r=checkList(extreme,groebnerBasis,fullNeighbourBasis,h,result, onlyCheckRays);
@@ -512,11 +512,11 @@ static PolynomialSet checkListStably(IntegerVectorList
   for(IntegerVectorList::const_iterator i=l.begin();i!=l.end();i++)
     {
       WeightReverseLexicographicTermOrder t(*i);
-      log2 fprintf(Stderr,"Taking initial forms with respect to:");
-      log2 AsciiPrinter(Stderr).printVector(*i);
-      log2 fprintf(Stderr,"\n");
+      gfan_log2 fprintf(Stderr,"Taking initial forms with respect to:");
+      gfan_log2 AsciiPrinter(Stderr).printVector(*i);
+      gfan_log2 fprintf(Stderr,"\n");
       PolynomialSet h2=groebnerBasis;
-      log2 fprintf(Stderr,"Done computing Gr\"obner basis.\n");
+      gfan_log2 fprintf(Stderr,"Done computing Gr\"obner basis.\n");
 
       log3 AsciiPrinter(Stderr).printPolynomialSet(h2);
       PolynomialSet wall=initialForms(h2,*i);
@@ -568,13 +568,13 @@ PolynomialSet guessInitialIdealWithoutMonomialStably(P
     }
 
   {
-    log2 fprintf(Stderr,"Computing extreme rays.\n");
+    gfan_log2 fprintf(Stderr,"Computing extreme rays.\n");
     //IntegerVectorList a;
     PolyhedralCone p=coneFromMarkedBasis(groebnerBasis);
     //PolyhedralCone p=PolyhedralCone(wallInequalities(groebnerBasis),a);
     IntegerVectorList extreme=p.extremeRays();
-    log2 fprintf(Stderr,"Extreme rays of Groebner cone:\n");
-    log2 AsciiPrinter(Stderr).printVectorList(extreme);
+    gfan_log2 fprintf(Stderr,"Extreme rays of Groebner cone:\n");
+    gfan_log2 AsciiPrinter(Stderr).printVectorList(extreme);
 
     bool result;
     PolynomialSet r=checkListStably(extreme,groebnerBasis,fullNeighbourBasis,h,result, onlyCheckRays);
