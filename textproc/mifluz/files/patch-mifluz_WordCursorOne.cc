--- mifluz/WordCursorOne.cc.orig	2007-11-22 11:41:12.000000000 +0100
+++ mifluz/WordCursorOne.cc	2007-11-22 11:41:27.000000000 +0100
@@ -44,7 +44,7 @@
 }
 
 // *****************************************************************************
-WordCursorOne::WordCursorOne(WordList *words, const WordKey &searchKey, int action = HTDIG_WORDLIST_WALKER) :
+WordCursorOne::WordCursorOne(WordList *words, const WordKey &searchKey, int action) :
   WordCursor(words->GetContext()),
   prefixKey(words->GetContext())
 {
