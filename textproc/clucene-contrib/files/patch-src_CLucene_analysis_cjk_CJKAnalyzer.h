--- src/CLucene/analysis/cjk/CJKAnalyzer.h	Fri Aug  1 17:55:43 2008
+++ src/CLucene/analysis/cjk/CJKAnalyzer.h.orig	Tue May 27 17:41:14 2008
@@ -52,7 +52,7 @@
      * character buffer, store the characters which are used to compose <br>
      * the returned Token
      */
-    TCHAR buffer[LUCENE_MAX_WORD_LEN];
+    TCHAR buffer[LUCENE_MAX_WORD_LEN+1];
 
     /**
      * I/O buffer, used to store the content of the input(one of the <br>
@@ -102,6 +102,33 @@
 };
 
 
+/** Represents a CJK analyzer.
+ *
+ *  Filters CJKTokenizer with StopFilter.
+ *
+ *  @author Che, Dong 
+ */
+ 
+class CJKAnalyzer : public CL_NS(analysis)::Analyzer
+{
+    private:
+        CL_NS(util)::CLSetList<const TCHAR*> stopTable;
+    public:
+        /** Builds an analyzer.*/
+        CJKAnalyzer();
+
+        /** Builds an analyzer with the given stop words. */
+        CJKAnalyzer(const TCHAR** stopWords);
+
+        ~CJKAnalyzer();
+
+        /** get token stream from input **/
+        CL_NS(analysis)::TokenStream* tokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader);
+
+        /** An array containing some common English words that are not usually useful for
+            searching and some double-byte interpunctions. */
+        static const TCHAR* STOP_WORDS[];
+};
 
 CL_NS_END2
 #endif
