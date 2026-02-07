--- src/tropicaltraverse.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/tropicaltraverse.cpp
@@ -199,7 +199,7 @@ static void printMarkedTermIdeal(PolynomialSet const &
 static void changeCone(PolynomialSet &coneGroebnerBasis, PolynomialSet &idealGroebnerBasis, IntegerVector const &ridgeVector, IntegerVector const &rayVector)
 {
   assert(idealGroebnerBasis.containsInClosedGroebnerCone(ridgeVector));
-  log2 cerr<<endl<<"Changing cone"<<endl;
+  gfan_log2 cerr<<endl<<"Changing cone"<<endl;
 
   assert(!containsMonomial(coneGroebnerBasis));
 
@@ -213,7 +213,7 @@ static void changeCone(PolynomialSet &coneGroebnerBasi
   WeightReverseLexicographicTermOrder T(rayVector);
 
   //  P<<ridgeIdeal;
-  log2 cerr<<"Computing initial Groebner basis"<<endl;
+  gfan_log2 cerr<<"Computing initial Groebner basis"<<endl;
   //  buchberger(&ridgeIdeal,T);
 
   ridgeIdeal=GE_groebnerBasis(ridgeIdeal,T,true,false);//Set to true?
@@ -224,7 +224,7 @@ static void changeCone(PolynomialSet &coneGroebnerBasi
   //  WeightTermOrder termOrder(termorderWeight(ridgeIdeal));
   WeightTermOrder termOrder(termorderWeight(ridgeIdealOld));
 
-  log2 cerr<<"Lifting"<<endl;
+  gfan_log2 cerr<<"Lifting"<<endl;
   PolynomialSet temp=ridgeIdealOld;
   temp.markAndScale(T);
   temp=temp.markedTermIdeal();
@@ -244,7 +244,7 @@ static void changeCone(PolynomialSet &coneGroebnerBasi
     }
   assert(g2.isMarked());
   //printMarkedTermIdeal(g2,"g2");
-  log2 cerr<<"Autoreducing"<<endl;
+  gfan_log2 cerr<<"Autoreducing"<<endl;
 
   //  autoReduce(&g2,LexicographicTermOrder());
   //PolynomialSet g2Old=g2;
@@ -260,7 +260,7 @@ static void changeCone(PolynomialSet &coneGroebnerBasi
   assert(idealGroebnerBasis.size()==oldSize);
   //  idealGroebnerBasis=g2;
   assert(!containsMonomial(coneGroebnerBasis));
-  log2 cerr<<"Done changing cone"<<endl<<endl;
+  gfan_log2 cerr<<"Done changing cone"<<endl<<endl;
 
   //  P<<coneGroebnerBasis;
   //  P<<idealGroebnerBasis;
@@ -279,7 +279,7 @@ static void changeCone(PolynomialSet &coneGroebnerBasi
     P<<coneGroebnerBasis;
     }*/
 
-  log2 cerr << "Number of terms in new basis: "<< g2.totalNumberOfTerms()<<endl;
+  gfan_log2 cerr << "Number of terms in new basis: "<< g2.totalNumberOfTerms()<<endl;
 }
 
 void printStack(list<pathStepFacet> const &facetStack, list<pathStepRidge> const &ridgeStack)
