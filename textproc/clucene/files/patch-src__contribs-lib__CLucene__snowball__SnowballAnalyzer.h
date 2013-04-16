--- src/contribs-lib/CLucene/snowball/SnowballAnalyzer.h.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/contribs-lib/CLucene/snowball/SnowballAnalyzer.h	2013-04-01 18:25:10.000000000 -0400
@@ -22,6 +22,7 @@
 class CLUCENE_CONTRIBS_EXPORT SnowballAnalyzer: public Analyzer {
   TCHAR* language;
   CLTCSetList* stopSet;
+  class SavedStreams;
 
 public:
   /** Builds the named analyzer with no stop words. */
@@ -37,6 +38,8 @@
       StandardFilter}, a {@link LowerCaseFilter} and a {@link StopFilter}. */
   TokenStream* tokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader);
   TokenStream* tokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader, bool deleteReader);
+
+  TokenStream* reusableTokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader);
 };
 
 CL_NS_END2
