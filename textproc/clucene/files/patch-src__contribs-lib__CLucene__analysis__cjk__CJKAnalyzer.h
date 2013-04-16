--- src/contribs-lib/CLucene/analysis/cjk/CJKAnalyzer.h.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/contribs-lib/CLucene/analysis/cjk/CJKAnalyzer.h	2013-03-29 18:46:22.000000000 -0400
@@ -39,7 +39,7 @@
      * character buffer, store the characters which are used to compose <br>
      * the returned Token
      */
-    TCHAR buffer[LUCENE_MAX_WORD_LEN];
+    TCHAR buffer[LUCENE_MAX_WORD_LEN+1];
 
     /**
      * I/O buffer, used to store the content of the input(one of the <br>
