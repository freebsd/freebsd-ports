--- src/app_groebnerfan.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/app_groebnerfan.cpp
@@ -74,7 +74,7 @@ class GroebnerFanApplication : public GFanApplication 
 	{
 	  log1 fprintf(Stderr,"Computing Groebner Basis...\n");
 	  buchberger(&g,StandardGradedLexicographicTermOrder());
-	  log2 AsciiPrinter(Stderr).printPolynomialSet(g);
+	  gfan_log2 AsciiPrinter(Stderr).printPolynomialSet(g);
 	}
       log1 fprintf(Stderr,"A reduced Groebner basis has been computed\n");
 
@@ -113,7 +113,7 @@ class GroebnerFanApplication : public GFanApplication 
 	    for(PolyhedralFan::coneIterator i=f1.conesBegin();i!=f1.conesEnd();i++)
 		{
 	    	static int t;
-	    	log2 cerr<<"Processing Cone "<<t++<<" which has dimension "<<i->dimension()<<endl;
+	    	gfan_log2 cerr<<"Processing Cone "<<t++<<" which has dimension "<<i->dimension()<<endl;
 	    	GroebnerFanTraverser traverser(groebnerBasisWithFullDimensionalIntersection(g,*i),*i);
     		SymmetricTargetCounterInterrupted target2(target,optionInterrupt.getValue());
 			symmetricTraverse(traverser,target2,&s);
