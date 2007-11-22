--- search/WordResults.cc.orig	2007-11-22 12:37:28.000000000 +0100
+++ search/WordResults.cc	2007-11-22 12:39:52.000000000 +0100
@@ -25,11 +25,11 @@
 
 static int wordResults_cmp(const DBT* a, const DBT* b)
 {
-  int length = (int)a->app_private;
+  size_t length = (size_t)a->app_private;
 
   WordKeyNum* a_values = (WordKeyNum*)a->data;
   WordKeyNum* b_values = (WordKeyNum*)b->data;
-  for(int i = 0; i < length; i++) {
+  for(size_t i = 0; i < length; i++) {
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
 
