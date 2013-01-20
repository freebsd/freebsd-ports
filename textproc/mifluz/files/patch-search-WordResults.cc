--- ./search/WordResults.cc.orig	2013-01-16 13:44:02.283818270 +0800
+++ ./search/WordResults.cc	2013-01-16 13:45:27.643665365 +0800
@@ -29,7 +29,7 @@
 
   WordKeyNum* a_values = (WordKeyNum*)a->data;
   WordKeyNum* b_values = (WordKeyNum*)b->data;
-  for(int i = 0; i < length; i++) {
+  for(long i = 0; i < length; i++) {
     if(a_values[i] != b_values[i]) {
       return a_values[i] > b_values[i] ? 1 : -1;
     }
@@ -198,7 +198,7 @@
   }
 
   if((error = ranked->set_re_len(ranked, sizeof(WordKeyNum) * document_length)) != 0) {
-    fprintf(stderr, "WordResults::Open ranked->set_re_len(%d) failed: %s\n", sizeof(WordKeyNum) * document_length, CDB_db_strerror(error));
+    fprintf(stderr, "WordResults::Open ranked->set_re_len(%lu) failed: %s\n", sizeof(WordKeyNum) * document_length, CDB_db_strerror(error));
     return NOTOK;
   }
 
