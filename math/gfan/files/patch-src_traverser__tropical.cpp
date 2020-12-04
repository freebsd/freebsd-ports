--- src/traverser_tropical.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/traverser_tropical.cpp
@@ -41,12 +41,12 @@ void TropicalTraverser::updatePolyhedralCone()
 
 void TropicalTraverser::changeCone(IntegerVector const &ridgeVector, IntegerVector const &rayVector)
 {
-log2 {
+gfan_log2 {
 	debug << "Interior point:"<<theCone.getUniquePoint()<<"\n";
 	debug << "Ridge:"<<ridgeVector<<"Ray:"<<rayVector<<"\n";
 }
 	assert(idealGroebnerBasis.containsInClosedGroebnerCone(ridgeVector));
-	  log2 cerr<<endl<<"Changing cone"<<endl;
+	  gfan_log2 cerr<<endl<<"Changing cone"<<endl;
 
 	//  assert(!containsMonomial(coneGroebnerBasis));
 
@@ -59,7 +59,7 @@ log2 {
 	  WeightReverseLexicographicTermOrder T(rayVector);
 
 	  //  P<<ridgeIdeal;
-	  log2 cerr<<"Computing initial Groebner basis"<<endl;
+	  gfan_log2 cerr<<"Computing initial Groebner basis"<<endl;
 	  //  buchberger(&ridgeIdeal,T);
 
 	  ridgeIdeal=GE_groebnerBasis(ridgeIdeal,T,true,false);//Set to true?
@@ -70,7 +70,7 @@ log2 {
 	  //  WeightTermOrder termOrder(termorderWeight(ridgeIdeal));
 	  WeightTermOrder termOrder(termorderWeight(ridgeIdealOld));
 
-	  log2 cerr<<"Lifting"<<endl;
+	  gfan_log2 cerr<<"Lifting"<<endl;
 	  PolynomialSet temp=ridgeIdealOld;
 	  temp.markAndScale(T);
 	  temp=temp.markedTermIdeal();
@@ -90,7 +90,7 @@ log2 {
 	    }
 	  assert(g2.isMarked());
 	  //printMarkedTermIdeal(g2,"g2");
-	  log2 cerr<<"Autoreducing"<<endl;
+	  gfan_log2 cerr<<"Autoreducing"<<endl;
 
 	  //  autoReduce(&g2,LexicographicTermOrder());
 	  //PolynomialSet g2Old=g2;
@@ -117,7 +117,7 @@ log2 {
 	  assert(idealGroebnerBasis.size()==oldSize);
 	  //  idealGroebnerBasis=g2;
 //	  assert(!containsMonomial(coneGroebnerBasis));
-	  log2 cerr<<"Done changing cone"<<endl<<endl;
+	  gfan_log2 cerr<<"Done changing cone"<<endl<<endl;
 
 	  //  P<<coneGroebnerBasis;
 	  //  P<<idealGroebnerBasis;
@@ -136,7 +136,7 @@ log2 {
 	    P<<coneGroebnerBasis;
 	    }*/
 
-	  log2 cerr << "Number of terms in new basis: "<< g2.totalNumberOfTerms()<<endl;
+	  gfan_log2 cerr << "Number of terms in new basis: "<< g2.totalNumberOfTerms()<<endl;
 
 
 	updatePolyhedralCone();
@@ -152,10 +152,10 @@ IntegerVectorList TropicalTraverser::link(IntegerVecto
 
 	//P<<tempIdeal;
 
-//	log2 D(tempIdeal);
+//	gfan_log2 D(tempIdeal);
 //	tempIdeal=saturatedIdeal(tempIdeal);//TODO: figure out if it is an advantage to saturate the ideal
 	/* That seems not to be the case. For example on Grassmann 3_8. Here most time would be spent saturating.*/
-//	log2 D(tempIdeal);
+//	gfan_log2 D(tempIdeal);
 
 	IntegerVectorList rays;
 
