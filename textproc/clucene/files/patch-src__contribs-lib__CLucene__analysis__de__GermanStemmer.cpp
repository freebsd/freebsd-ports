--- src/contribs-lib/CLucene/analysis/de/GermanStemmer.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/contribs-lib/CLucene/analysis/de/GermanStemmer.cpp	2013-01-08 17:03:27.000000000 -0500
@@ -144,7 +144,7 @@
           {
             buffer.setCharAt( i, _T('$') );
             buffer.deleteChars( i + 1, i + 3 );
-            substCount =+ 2;
+            substCount += 2;
           }
           else if ( c == _T('c') && buffer.charAt( i + 1 ) == _T('h') ) {
             buffer.setCharAt( i, 0xa7 ); // section sign in UTF-16
