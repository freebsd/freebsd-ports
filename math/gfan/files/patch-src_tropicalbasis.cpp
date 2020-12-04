--- src/tropicalbasis.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/tropicalbasis.cpp
@@ -118,10 +118,10 @@ PolynomialSet tropicalBasisOfCurve(int n, PolynomialSe
 	PolynomialSet originalG=g;
 //  bool prebasis=true;
 //  debug<<"PREBASIS="<<prebasis<<"\n";
-  log2 debug<<"TropicalBasis begin\n";
-	log2 debug<<g;
+  gfan_log2 debug<<"TropicalBasis begin\n";
+	gfan_log2 debug<<g;
 	int homog=linealitySpaceDimension;
-	log2 D(linealitySpaceDimension);
+	gfan_log2 D(linealitySpaceDimension);
   assert(homog>0 || n==0);
   TimerScope ts(&iterativeTropicalBasisTimer);
   PolyhedralFan f(n);
@@ -148,7 +148,7 @@ restart:
 
 	  if(containsNoMonomialCache.count(relativeInteriorPoint)>0)
 	    {
-	      log2 fprintf(Stderr,"Weight vector found in cache.... contains no monomial.\n");
+	      gfan_log2 fprintf(Stderr,"Weight vector found in cache.... contains no monomial.\n");
 	    }
 	  else
 	    {
@@ -163,9 +163,9 @@ restart:
 	            }
 	        }*/
 	      WeightReverseLexicographicTermOrder t(relativeInteriorPoint);
-	      log2 fprintf(Stderr,"Computing Gr\"obner basis with respect to:");
-	      log2 AsciiPrinter(Stderr).printVector(relativeInteriorPoint);
-	      log2 fprintf(Stderr,"\n");
+	      gfan_log2 fprintf(Stderr,"Computing Gr\"obner basis with respect to:");
+	      gfan_log2 AsciiPrinter(Stderr).printVector(relativeInteriorPoint);
+	      gfan_log2 fprintf(Stderr,"\n");
 	      PolynomialSet h2=originalG;//g;//<------------------- Using the original set here speeds up things a lot in the starting cone via stable intersections algorithm
   //            debug<<"g"<<g;
 
@@ -178,7 +178,7 @@ restart:
 	     // buchberger(&h2,t);
 	      h2=GE_groebnerBasis(h2,t,true/*autoreduce*/,true/*saturate*/);
         //      debug<<"h2"<<h2;
-	      log2 fprintf(Stderr,"Done computing Gr\"obner basis.\n");
+	      gfan_log2 fprintf(Stderr,"Done computing Gr\"obner basis.\n");
 
 	  //    debug<<h2;
 //	      log3 AsciiPrinter(Stderr).printPolynomialSet(h2);
@@ -187,17 +187,17 @@ restart:
 
 	      if(containsMonomial(wall))
 		{
-		  log2 fprintf(Stderr,"Initial ideal contains a monomial.\n");
+		  gfan_log2 fprintf(Stderr,"Initial ideal contains a monomial.\n");
 		  Polynomial m(computeTermInIdeal(wall));
-		  log2 fprintf(Stderr,"Done computing term in ideal\n");
+		  gfan_log2 fprintf(Stderr,"Done computing term in ideal\n");
 
 //		  Polynomial temp=m-division(m,h2,LexicographicTermOrder());
 		  Polynomial temp=m-division(m,h2,t);
 		  g.push_back(temp);
 
-		  log2 fprintf(Stderr,"Adding element to basis:\n");
-		  log2 AsciiPrinter(Stderr).printPolynomial(temp);
-		  log2 fprintf(Stderr,"\n");
+		  gfan_log2 fprintf(Stderr,"Adding element to basis:\n");
+		  gfan_log2 AsciiPrinter(Stderr).printPolynomial(temp);
+		  gfan_log2 fprintf(Stderr,"\n");
 
 		  *intersectionFan=refinement(*intersectionFan,PolyhedralFan::bergmanOfPrincipalIdeal(temp),linealitySpaceDimension,true);
 		  break;
@@ -207,7 +207,7 @@ restart:
 		  if(i->dimension()<=1+homog)
 		    //if(!containsMonomial(wall) && i->dimension()<=1+homog)//line for testing perturbation code
 		    {
-		      log2 fprintf(Stderr,"Initial ideal contains no monomial... caching weight vector.\n");
+		      gfan_log2 fprintf(Stderr,"Initial ideal contains no monomial... caching weight vector.\n");
 		      containsNoMonomialCache.insert(relativeInteriorPoint);
 		    }
 		  else
@@ -227,10 +227,10 @@ restart:
 		      dual.canonicalize();
 		      IntegerVectorList basis=dual.getEquations();
 		      PolynomialSet witnessLiftBasis=h2;//basis with respect to relativeInteriorPoint
-		      log2 debug<<"basis"<<basis<<"\n";
+		      gfan_log2 debug<<"basis"<<basis<<"\n";
 		      for(IntegerVectorList::const_iterator j=basis.begin();j!=basis.end();j++)
 			{
-			  log2 debug<<"wall"<<wall<<"\n";
+			  gfan_log2 debug<<"wall"<<wall<<"\n";
 			  WeightReverseLexicographicTermOrder t(*j);
 			  PolynomialSet h3=wall;
 //			  buchberger(&h3,t);
@@ -238,7 +238,7 @@ restart:
 			  wall=initialFormsAssumeMarked(h3,*j);
 			  witnessLiftBasis=liftBasis(h3,witnessLiftBasis);
 			}
-                      log2 debug<<"wall"<<wall<<"\n";
+                      gfan_log2 debug<<"wall"<<wall<<"\n";
 		      if(containsMonomial(wall))
 			{
 			  Polynomial m(computeTermInIdeal(wall));
@@ -259,8 +259,8 @@ restart:
       if(i==intersectionFan->conesEnd())break;
     }
 
-  log2 debug<<"TropicalBasis end\n";
-  log2 cerr <<"RETURNING";
+  gfan_log2 debug<<"TropicalBasis end\n";
+  gfan_log2 cerr <<"RETURNING";
   return g;
 }
 
