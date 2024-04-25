--- lib/tests/test_wordtokenizer_main.cpp.orig	2018-10-09 17:21:21 UTC
+++ lib/tests/test_wordtokenizer_main.cpp
@@ -3,15 +3,16 @@
 #endif
 
 #include <iostream>
-
-#include "asserttestexit.h"
 #include "srchilite/wordtokenizer.h"
-#include "srchilite/tostringcollection.h"
 
 using namespace std;
 using namespace srchilite;
 
 static ostream &operator <<(ostream &os, const WordTokenizer::WordTokenizerResults::value_type &);
+
+#include "asserttestexit.h"
+#include "srchilite/tostringcollection.h"
+
 
 ostream &operator <<(ostream &os, const WordTokenizer::WordTokenizerResults::value_type &token) {
     if (token.first.size()) {
