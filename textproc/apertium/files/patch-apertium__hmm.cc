--- apertium/hmm.cc.orig
+++ apertium/hmm.cc
@@ -141,7 +141,7 @@
   int N = td->getN();
   int M = td->getM();
   int i, j, k, k1, k2, nw=0;
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
   double classes_ocurrences[M]; //M = Number of ambiguity classes
   double classes_pair_ocurrences[M][M];
   double tags_estimate[N]; //N = Number of tags (states)
@@ -159,7 +159,7 @@
   
   TaggerWord *word=NULL;
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
   for(k=0; k<M; k++) {
     classes_ocurrences[k]=1; 
     for (k2=0; k2<M; k2++)
@@ -204,7 +204,7 @@
 
   //Estimation of the number of time each tags occurs in the training text
   for(i=0; i<N; i++) {  
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
     tags_estimate[i]=0;
 #endif
     for(k=0; k<M;  k++) { 
@@ -214,7 +214,7 @@
     }
   }
   
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
   //Estimation of the number of times each tag pair occurs
   for(i=0; i<N; i++)
     for(j=0; j<N; j++)
@@ -270,7 +270,7 @@
   int i, j, k, nw=0;
   int N = td->getN();
   int M = td->getM();
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
   double tags_pair[N][N];
   double emission[N][M];
 #else
@@ -288,7 +288,7 @@
   
   set<TTag> tags;
 
-#ifdef __GNUC__ 
+#if defined(__GNUC__) && !defined(__clang__)
   // Init counters - each event appears at least once. 
   // Espected likelihood estimate (ELE) with a fixed initial count of 1
   for(i=0; i<N; i++) {
@@ -750,12 +750,12 @@
   
   double prob, loli, x;
   int N = td->getN();  
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
   double alpha[2][N];
   vector<TTag> best[2][N];
 #else
   vector <vector <double> > alpha(2, vector<double>(N));
-  vector <vector <vector<TTag>> > best(2, vector<vector<TTag>>(N));
+  vector <vector <vector<TTag> > > best(2, vector<vector<TTag> >(N));
 #endif
   
   vector <TaggerWord> wpend; 
@@ -799,7 +799,7 @@
          
     k = output[tags];  //Ambiguity class the word belongs to
     
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
     clear_array_double(alpha[nwpend%2], N);    
     clear_array_vector(best[nwpend%2], N);
 #endif
