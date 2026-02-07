--- src/bergman.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/bergman.cpp
@@ -79,15 +79,15 @@ BergmanFan bergmanRayIntersection(PolynomialSet const 
   //  fprintf(Stderr,"---------------------------------------------------------\n");
 
 
-  log2  cerr<<"BBLABL";
+  gfan_log2  cerr<<"BBLABL";
   for(IntegerVectorList::const_iterator i=rays.begin();i!=rays.end();i++)
     {
-      log2 cerr<<"1";
+      gfan_log2 cerr<<"1";
       PolynomialSet g=idealGroebnerBasis;
       g=GE_groebnerBasis(g,WeightReverseLexicographicTermOrder(*i),true,false);//Set to true?
       //      buchberger(&g,WeightReverseLexicographicTermOrder(*i));
       PolynomialSet cg=initialFormsAssumeMarked(g,*i);
-      log2 cerr<<"2";
+      gfan_log2 cerr<<"2";
  
       bool inList=false;
       for(BergmanFan::MaximalConeList::const_iterator j=bfan.cones.begin();j!=bfan.cones.end();j++)
@@ -98,14 +98,14 @@ BergmanFan bergmanRayIntersection(PolynomialSet const 
 	      break;
 	    }
 	}
-      log2 cerr<<"3";
+      gfan_log2 cerr<<"3";
       if(!inList)
 	{
 	  bfan.cones.push_back(BergmanFan::MaximalCone(cg,g,true,maximalConeLabel++));
 	}
-      log2 cerr<<"4";
+      gfan_log2 cerr<<"4";
     }
-  log2 cerr<<"BBLAB  END";
+  gfan_log2 cerr<<"BBLAB  END";
   //  AsciiPrinter temp(Stderr);
   //  bfan.print(temp);
   return bfan;
@@ -631,7 +631,7 @@ BergmanFan bergman(PolynomialSet const &coneGroebnerBa
 			     symmetry checks were algebraic and not
 			     geometric*/
 			  //  assert(i->idealGroebnerBasis.isMarked());
-			  log2 cerr<<"8";
+			  gfan_log2 cerr<<"8";
 
 			  PolynomialSet g2(theRing);
 			  WeightTermOrder termOrder(termorderWeight(initialIdeal));
@@ -639,14 +639,14 @@ BergmanFan bergman(PolynomialSet const &coneGroebnerBa
 			  for(PolynomialSet::const_iterator j=i->idealGroebnerBasis.begin();j!=i->idealGroebnerBasis.end();j++)
 			    g2.push_back(divisionLift(*j, initialIdeal, current.idealGroebnerBasis, termOrder));
 			  assert(g2.isMarked());
-			  log2 cerr<<"9";
+			  gfan_log2 cerr<<"9";
 			
 			 
 			  if(1)
 			    {
-			      log2 cerr << "AUTOREDUCTION";
+			      gfan_log2 cerr << "AUTOREDUCTION";
 			      autoReduce(&g2,LexicographicTermOrder());
-			      log2 cerr << "AUTOREDUCTION END"<<endl;
+			      gfan_log2 cerr << "AUTOREDUCTION END"<<endl;
 			    }
 			  else
 			    {
@@ -655,17 +655,17 @@ BergmanFan bergman(PolynomialSet const &coneGroebnerBa
 			      log0 cerr << "RESTRICTED AUTOREDUCTION END"<<endl;
 			    }
 			  ConeOrbit tempConeOrbit(*symmetryGroup,i->coneGroebnerBasis,g2,-1);
-			  log2 cerr<<"0";
+			  gfan_log2 cerr<<"0";
 			  IntegerVector relIntFacetVector=tempConeOrbit.getStableRay();
 
-			  log2 cerr<<"A";
+			  gfan_log2 cerr<<"A";
 
 			  int label=-1;
 			  IntegerVector labelPermutation;
 			  if(!active.containsAndMark(relIntFacetVector,relIntRidgeVector,&label,&labelPermutation))
 			    //			  if(!active.containsAndMark(i->coneGroebnerBasis,initialIdeal,&label,&labelPermutation))
 			    {
-			  log2 cerr<<"B";
+			  gfan_log2 cerr<<"B";
 			      if(!ret.contains(i->coneGroebnerBasis))
 				{
 				  label=maximalConeLabel++;
@@ -680,13 +680,13 @@ BergmanFan bergman(PolynomialSet const &coneGroebnerBa
 				{
 				  assert(0);//Can this ever happen? REMOVE JAN 2009
 				}
-			  log2 cerr<<"C";
+			  gfan_log2 cerr<<"C";
 			    }
-			  log2 cerr<<"D";
+			  gfan_log2 cerr<<"D";
 			  ret.codimensionOneCones.back().incidenceList.push_back(label);
-			  log2 cerr<<"E";
+			  gfan_log2 cerr<<"E";
 			  ret.codimensionOneCones.back().incidencePermutationList.push_back(labelPermutation);
-			  log2 cerr<<"F";
+			  gfan_log2 cerr<<"F";
 			}
 		    }
 		    //		  else
@@ -898,9 +898,9 @@ PolyhedralFan BergmanFan::toPolyhedralFan()const
       //PolyhedralCone c1(wallInequalities(i->idealGroebnerBasis),wallInequalities(i->coneGroebnerBasis));
       //      PolyhedralCone c1(wallFlipableNormals(i->idealGroebnerBasis,false),wallInequalities(i->coneGroebnerBasis),n);
       PolyhedralCone c1=i->theCone;
-      log2 fprintf(Stderr,"Cononicalising...\n");
+      gfan_log2 fprintf(Stderr,"Cononicalising...\n");
       c1.canonicalize();
-      log2 fprintf(Stderr,"... done canonicalising...\n");
+      gfan_log2 fprintf(Stderr,"... done canonicalising...\n");
       //      fprintf(Stderr,"a\n");
       //      for(SymmetryGroup::ElementContainer::const_iterator j=symmetryGroup.elements.begin();j!=symmetryGroup.elements.end();j++)
       //	{
