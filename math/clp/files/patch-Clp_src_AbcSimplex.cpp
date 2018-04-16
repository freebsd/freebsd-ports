--- Clp/src/AbcSimplex.cpp.orig	2018-04-16 06:55:57 UTC
+++ Clp/src/AbcSimplex.cpp
@@ -368,19 +368,19 @@ AbcSimplex::gutsOfInitialize(int numberR
     // say Steepest pricing
     abcDualRowPivot_ = new AbcDualRowSteepest();
     abcPrimalColumnPivot_ = new AbcPrimalColumnSteepest();
-    internalStatus_ = newArray(reinterpret_cast<unsigned char *>(NULL),
+    internalStatus_ = newArray(nullptr,
 			       sizeArray+maximumNumberTotal_);
-    abcLower_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-    abcUpper_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-    abcCost_ = newArray(reinterpret_cast<double *>(NULL),sizeArray+maximumNumberTotal_);
-    abcDj_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-    abcSolution_ = newArray(reinterpret_cast<double *>(NULL),sizeArray+maximumNumberTotal_);
-    //fromExternal_ = newArray(reinterpret_cast<int *>(NULL),sizeArray);
-    //toExternal_ = newArray(reinterpret_cast<int *>(NULL),sizeArray);
-    scaleFromExternal_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-    offset_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-    abcPerturbation_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-    abcPivotVariable_ = newArray(reinterpret_cast<int *>(NULL),maximumAbcNumberRows_);
+    abcLower_ = newArray(nullptr,sizeArray);
+    abcUpper_ = newArray(nullptr,sizeArray);
+    abcCost_ = newArray(nullptr,sizeArray+maximumNumberTotal_);
+    abcDj_ = newArray(nullptr,sizeArray);
+    abcSolution_ = newArray(nullptr,sizeArray+maximumNumberTotal_);
+    //fromExternal_ = newArray(nullptr,sizeArray);
+    //toExternal_ = newArray(nullptr,sizeArray);
+    scaleFromExternal_ = newArray(nullptr,sizeArray);
+    offset_ = newArray(nullptr,sizeArray);
+    abcPerturbation_ = newArray(nullptr,sizeArray);
+    abcPivotVariable_ = newArray(nullptr,maximumAbcNumberRows_);
     // Fill perturbation array
     setupPointers(maximumAbcNumberRows_,maximumAbcNumberColumns_);
     fillPerturbation(0,maximumNumberTotal_);
@@ -554,19 +554,19 @@ AbcSimplex::createSubProblem(int numberC
   subProblem->maximumNumberTotal_= maximumAbcNumberRows_+numberColumns;
   subProblem->numberTotalWithoutFixed_= subProblem->numberTotal_;
   int sizeArray=2*subProblem->maximumNumberTotal_+maximumAbcNumberRows_;
-  subProblem->internalStatus_ = newArray(reinterpret_cast<unsigned char *>(NULL),
+  subProblem->internalStatus_ = newArray(nullptr,
 					 sizeArray+subProblem->maximumNumberTotal_);
-  subProblem->abcLower_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-  subProblem->abcUpper_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-  subProblem->abcCost_ = newArray(reinterpret_cast<double *>(NULL),sizeArray+subProblem->maximumNumberTotal_);
-  subProblem->abcDj_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-  subProblem->abcSolution_ = newArray(reinterpret_cast<double *>(NULL),sizeArray+subProblem->maximumNumberTotal_);
-  //fromExternal_ = newArray(reinterpret_cast<int *>(NULL),sizeArray);
-  //toExternal_ = newArray(reinterpret_cast<int *>(NULL),sizeArray);
-  subProblem->scaleFromExternal_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-  subProblem->offset_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-  subProblem->abcPerturbation_ = newArray(reinterpret_cast<double *>(NULL),sizeArray);
-  subProblem->abcPivotVariable_ = newArray(reinterpret_cast<int *>(NULL),maximumAbcNumberRows_);
+  subProblem->abcLower_ = newArray(nullptr,sizeArray);
+  subProblem->abcUpper_ = newArray(nullptr,sizeArray);
+  subProblem->abcCost_ = newArray(nullptr,sizeArray+subProblem->maximumNumberTotal_);
+  subProblem->abcDj_ = newArray(nullptr,sizeArray);
+  subProblem->abcSolution_ = newArray(nullptr,sizeArray+subProblem->maximumNumberTotal_);
+  //fromExternal_ = newArray(nullptr,sizeArray);
+  //toExternal_ = newArray(nullptr,sizeArray);
+  subProblem->scaleFromExternal_ = newArray(nullptr,sizeArray);
+  subProblem->offset_ = newArray(nullptr,sizeArray);
+  subProblem->abcPerturbation_ = newArray(nullptr,sizeArray);
+  subProblem->abcPivotVariable_ = newArray(nullptr,maximumAbcNumberRows_);
   subProblem->setupPointers(maximumAbcNumberRows_,numberColumns);
   // could use arrays - but for now be safe
   int * backward = new int [numberFullColumns+numberRows_];
