--- src/contribs-lib/CLucene/analysis/de/GermanStemmer.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/contribs-lib/CLucene/analysis/de/GermanStemmer.cpp	2013-03-27 17:12:31.000000000 -0400
@@ -16,7 +16,7 @@
     }
 
     TCHAR* GermanStemmer::stem(const TCHAR* term, size_t length) {
-      if (length < 0) {
+      if (length <= 0) {
         length = _tcslen(term);
       }
 
@@ -38,7 +38,7 @@
     }
 
     bool GermanStemmer::isStemmable(const TCHAR* term, size_t length) const {
-      if (length < 0) {
+      if (length <= 0) {
         length = _tcslen(term);
       }
       for (size_t c = 0; c < length; c++) {
@@ -144,7 +144,7 @@
           {
             buffer.setCharAt( i, _T('$') );
             buffer.deleteChars( i + 1, i + 3 );
-            substCount =+ 2;
+            substCount += 2;
           }
           else if ( c == _T('c') && buffer.charAt( i + 1 ) == _T('h') ) {
             buffer.setCharAt( i, 0xa7 ); // section sign in UTF-16
