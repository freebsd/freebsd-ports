--- src/core/CLucene/search/ConstantScoreQuery.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/search/ConstantScoreQuery.cpp	2013-03-27 17:34:06.000000000 -0400
@@ -25,14 +25,17 @@
     BitSet* bits;
     const float_t theScore;
     int32_t _doc;
+    bool shouldDelete;
 
 public:
     ConstantScorer(Similarity* similarity, IndexReader* reader, Weight* w, Filter* filter) : Scorer(similarity),
         bits(filter->bits(reader)), theScore(w->getValue()), _doc(-1)
     {
+        shouldDelete = filter->shouldDeleteBitSet(bits);
     }
     virtual ~ConstantScorer() {
-        _CLLDELETE(bits);
+        if ( shouldDelete)
+            _CLLDELETE(bits);
     }
 
     bool next() {
