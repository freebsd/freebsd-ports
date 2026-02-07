--- src/halfopencone.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/halfopencone.cpp
@@ -602,7 +602,7 @@ void tropicalHyperSurfaceIntersectionWithProcessor(int
       intersectionOld.print(&P);
 	*/
       }
-  log2 fprintf(Stderr,"Halfopen intersection completed.\n");
+  gfan_log2 fprintf(Stderr,"Halfopen intersection completed.\n");
 }
 
 PolyhedralFan tropicalHyperSurfaceIntersectionClosed(int dimension, PolynomialSet const &g, PolyhedralCone *restrictingCone, bool expand, bool saveResult, int intervalLow, int intervalHigh)
@@ -1296,7 +1296,7 @@ struct RecursionData (public)
 
     if(index == fans.size())
       {
-	log2 fprintf(Stderr,"ADDING CONE\n");
+	gfan_log2 fprintf(Stderr,"ADDING CONE\n");
 	//ret.push_back(current);
 	processor.process(current,chosenFans,chosen);
 	numberOfUsefulCalls++;
@@ -1339,7 +1339,7 @@ struct RecursionData (public)
 
 	static int iterationNumber;
 	if(!(iterationNumber++ & 31))
-	  log2
+	  gfan_log2
 	{
 	  fprintf(Stderr,"Iteration level:%i, Chosen fan:%i, Number of candidates:%i, Iteration Number:%i, Useful (%i/%i)=%f\n",index,bestIndex,bestNumberOfCandidates,iterationNumber,numberOfUsefulCalls,totalNumberOfCalls,float(numberOfUsefulCalls)/totalNumberOfCalls);
 	  fprintf(Stderr,"Chosen fans vector: ");
@@ -1490,7 +1490,7 @@ struct RecursionData (public)
   }
   bool closure()
   {
-    log2 cerr<<"computing closure"<<endl;
+    gfan_log2 cerr<<"computing closure"<<endl;
     bool ret=false;
     int a=0;
     for(int f1=0;f1<fans.size();f1++)
@@ -1532,8 +1532,8 @@ struct RecursionData (public)
 		  }
 	      }
       }
-    log2 fprintf(Stderr,"%i FOR FREE\n",a);
-    log2 cerr<<"done computing closure"<<endl;
+    gfan_log2 fprintf(Stderr,"%i FOR FREE\n",a);
+    gfan_log2 cerr<<"done computing closure"<<endl;
     return ret;
   }
 
@@ -1607,8 +1607,8 @@ struct RecursionData (public)
 		freeLPs++;
 	      }
     //    table.print();
-//    log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data2.table.numberOfSolvedLPs);
-    log2 fprintf(Stderr,"Number of infeassible LPs discovered from higherdimensional cones: %i\n",freeLPs);
+//    gfan_log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data2.table.numberOfSolvedLPs);
+    gfan_log2 fprintf(Stderr,"Number of infeassible LPs discovered from higherdimensional cones: %i\n",freeLPs);
   }
 };
 
@@ -1630,9 +1630,9 @@ void tropicalHyperSurfaceIntersection(int dimension, P
 	HalfOpenConeList l,lf;
 	buildFanFromPolynomial(*i, &lf, &l, &(parents[I]),restrictingCone);
 
-	log2 AsciiPrinter(Stderr).printVector(parents[I]);
+	gfan_log2 AsciiPrinter(Stderr).printVector(parents[I]);
 
-	log2 fprintf(Stderr,"\n");
+	gfan_log2 fprintf(Stderr,"\n");
 
 	vector<HalfOpenCone> L;
 	for(HalfOpenConeList::const_iterator i=l.begin();i!=l.end();i++)
@@ -1658,7 +1658,7 @@ void tropicalHyperSurfaceIntersection(int dimension, P
 //  data.table.print();//HERE
   IntegerVectorList empty;
   data.rek(0, HalfOpenCone(dimension,empty,empty,empty));
-  log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data.table.numberOfSolvedLPs);
+  gfan_log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data.table.numberOfSolvedLPs);
 }
 
 
@@ -1861,7 +1861,7 @@ void tropicalHyperSurfaceIntersectionInSubspace(int di
     are gotten as the pull-back of the lower dimensional equations by
     this normal form map.
    */
-  log2 cerr<<"Projecting Newton polytopes modulo the homogeneity space.";
+  gfan_log2 cerr<<"Projecting Newton polytopes modulo the homogeneity space.";
 
   int N=G.getRing().getNumberOfVariables();
   IntegerVectorList w=wallInequalities(G);
@@ -1887,7 +1887,7 @@ void tropicalHyperSurfaceIntersectionInSubspace(int di
       restrictingCone=&restrictedConeNew;
     }
 
-  log2 cerr<<"Done projecting Newton polytopes modulo the homogeneity space.";
+  gfan_log2 cerr<<"Done projecting Newton polytopes modulo the homogeneity space.";
   /*
     Now do the computation with the new set of polynomials.
    */
@@ -1895,7 +1895,7 @@ void tropicalHyperSurfaceIntersectionInSubspace(int di
   /*
     Here follows restriction to subspace cut out by the binomials.
    */
-  log2 cerr<<"Restricting to subspace determined by binomials and computing tropical hypersurfaces.";
+  gfan_log2 cerr<<"Restricting to subspace determined by binomials and computing tropical hypersurfaces.";
 
   int n=g.getRing().getNumberOfVariables();
   IntegerVectorList equations;
@@ -1937,12 +1937,12 @@ void tropicalHyperSurfaceIntersectionInSubspace(int di
   for(PolynomialSet::const_iterator i=g.begin();i!=g.end();i++)
     if(i->numberOfTerms()!=2)
       {
-	log2 cerr << I;
+	gfan_log2 cerr << I;
 	HalfOpenConeList l,lf;
-	log2 cerr<< "Building fan"<<endl;
+	gfan_log2 cerr<< "Building fan"<<endl;
 	buildFanFromPolynomial(*i, &lf, &l, &(parents[I]),restrictingCone);
-	log2 cerr<< "Number of cones:" << lf.size()<<","<< l.size()<<endl;
-	log2 cerr<< "rewriting"<<endl;
+	gfan_log2 cerr<< "Number of cones:" << lf.size()<<","<< l.size()<<endl;
+	gfan_log2 cerr<< "rewriting"<<endl;
 
 	vector<HalfOpenCone> L;
 	for(HalfOpenConeList::const_iterator i=l.begin();i!=l.end();i++)
@@ -1953,10 +1953,10 @@ void tropicalHyperSurfaceIntersectionInSubspace(int di
 
 	fullDimFanList.push_back(F);
 	coDimOneFanList.push_back(L);
-	log2 cerr<< "Done Building fan"<<endl;
+	gfan_log2 cerr<< "Done Building fan"<<endl;
 	I++;
       }
-  log2 cerr<<"Done computing tropical hypersurfaces.";
+  gfan_log2 cerr<<"Done computing tropical hypersurfaces.";
 
   /* Now we must create a new HalfOpenConeProcessor and tell it how to expand a cone.
      We must insert the pivot columns from A and add in the equtions gotten from the binomials.
@@ -1974,12 +1974,12 @@ void tropicalHyperSurfaceIntersectionInSubspace(int di
 
 
   IntegerVectorList empty;
-  log2 cerr<<"Doing intersection.";
+  gfan_log2 cerr<<"Doing intersection.";
   if(intervalHigh!=-1)data.setInterval(intervalLow,intervalHigh);
   data.rek(0, HalfOpenCone(nonPivots.size(),empty,empty,empty));
-  log2 cerr<<"Done doing intersection.";
+  gfan_log2 cerr<<"Done doing intersection.";
   //  data.rek(0, HalfOpenCone(dimension,empty,empty,empty));
-  //  log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data.table.numberOfSolvedLPs);
+  //  gfan_log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data.table.numberOfSolvedLPs);
 
   /*  HalfOpenConeList ret;
 
@@ -2151,7 +2151,7 @@ bool hasMixedCellOfDimension(PolynomialSet const &g, i
   IntegerVectorList empty;
   data.rek(0, HalfOpenCone(g.getRing().getNumberOfVariables(),empty,empty,empty));
 
-  log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data.table.numberOfSolvedLPs);
+  gfan_log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data.table.numberOfSolvedLPs);
 
   if(maximalSeen)*maximalSeen=p.getMaximalDimensionFound();
 
@@ -2185,7 +2185,7 @@ bool hasMixedCellOfDimension(list<list<IntegerVector> 
   IntegerVectorList empty;
   data.rek(0, HalfOpenCone(/*g.getRing().getNumberOfVariables()*/d,empty,empty,empty));
 
-  log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data.table.numberOfSolvedLPs);
+  gfan_log2 fprintf(Stderr,"LPs solved:%i for relation table\n",data.table.numberOfSolvedLPs);
 
   if(maximalSeen)*maximalSeen=p.getMaximalDimensionFound();
 
