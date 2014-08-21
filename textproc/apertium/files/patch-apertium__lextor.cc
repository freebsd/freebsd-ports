--- apertium/lextor.cc.orig
+++ apertium/lextor.cc
@@ -277,7 +277,7 @@
 	    //Note: Words in the context can also be ambiguous (with more than one lexical choice)
 	    //In that case the count will come from all the possible
 	    //translations 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 	    vector<wstring> translation_buffer[buffer_max_size];
 	    wstring reduced_buffer[buffer_max_size];
 #else
@@ -340,7 +340,7 @@
 		  //The counts of the TL co-occurrence model are transferred to the SL. If the SL word is ambiguous
 		  //it will have more than one translation into TL, so we need to normalize using the frequency of words
 		  //in the TL
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 		  double translation_weighs[translation_buffer[i].size()];
 #else
 		  vector <double> translation_weighs(translation_buffer[i].size());
@@ -686,7 +686,7 @@
 
 int 
 LexTor::estimate_winner_lch_voting(deque<LexTorWord>& window, int word_index, double weigth_exponent) {
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
   double lexchoices_count[window[word_index].n_lexical_choices()];
 #else
   vector <double> lexchoices_count(window[word_index].n_lexical_choices());
@@ -879,7 +879,7 @@
     exit(EXIT_FAILURE);
   }  
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
   double lexchoices_count[window[word_index].n_lexical_choices()];
   vector<wstring> translation_window[window.size()];
   wstring reduced_window[window.size()];
@@ -935,7 +935,7 @@
 	//If the SL word is ambiguous it will have more than one
 	//translation into TL, so we need to normalize using the
 	//frequency of words in the TL
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 	double translation_weighs[translation_window[k].size()];
 #else
     vector <double> translation_weighs(translation_window[k].size());
