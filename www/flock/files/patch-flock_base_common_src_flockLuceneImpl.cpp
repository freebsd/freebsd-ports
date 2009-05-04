--- flock/base/lucene/src/flockLuceneImpl.cpp.orig	2009-05-01 22:20:06.000000000 +0200
+++ flock/base/lucene/src/flockLuceneImpl.cpp	2009-05-01 22:20:26.000000000 +0200
@@ -283,7 +283,6 @@
   TokenStream* tokenStream(const TCHAR* fieldName, Reader* reader) {
     TokenStream* ret = new StandardTokenizer(reader);
     ret = new StandardFilter(ret, true);
-    ret = new LowerCaseFilter(ret, true);
     return ret;
   }
 };
