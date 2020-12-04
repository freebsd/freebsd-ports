--- src/buchberger.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/buchberger.cpp
@@ -65,7 +65,7 @@ void buchberger/*Simple*/(PolynomialSet *g, TermOrder 
 		return buchberger2(g, termOrder, allowSaturation);
 	//return buchbergerChain(g, termOrder, allowSaturation);
 	PolynomialRing theRing=g->getRing();
-  //  log2 fprintf(Stderr,"ENTERING buchberger\n");
+  //  gfan_log2 fprintf(Stderr,"ENTERING buchberger\n");
   TimerScope ts(&buchbergerTimer);
   PolynomialSet sPolynomials(theRing);
 
@@ -136,11 +136,11 @@ void buchberger/*Simple*/(PolynomialSet *g, TermOrder 
     //  else
     //	  pout<<"ZERO\n";
     }
-  //log2  fprintf(Stderr," buchberger minimize\n");
+  //gfan_log2  fprintf(Stderr," buchberger minimize\n");
   minimize(g);
-  //log2 fprintf(Stderr," buchberger autoreduce\n");
+  //gfan_log2 fprintf(Stderr," buchberger autoreduce\n");
   autoReduce(g,termOrder);
-  //log2 fprintf(Stderr,"LEAVING buchberger\n\n");
+  //gfan_log2 fprintf(Stderr,"LEAVING buchberger\n\n");
 
   cerr<<"NumberOfReductions: "<<numberOfReductions<<std::endl;
 }
@@ -496,7 +496,7 @@ void buchberger2(PolynomialSet *g, TermOrder const &te
           g->push_back(p);
           G.push_back(p);
           numberOfUsefulCriticalPairs++;
-          log2
+          gfan_log2
           {
         	  static int t;
         	  if(((++t)&=31)==0)
@@ -587,7 +587,7 @@ bool isMarkedGroebnerBasis(PolynomialSet const &g)
   int counter=0;
   for(PolynomialSet::const_iterator i=g.begin();i!=g.end();i++)
     {
-    log2 fprintf(Stderr,"%i ",counter++);
+    gfan_log2 fprintf(Stderr,"%i ",counter++);
     for(PolynomialSet::const_iterator j=i;j!=g.end();j++)
       if(!relativelyPrime(i->getMarked().m.exponent,j->getMarked().m.exponent))
 	{
