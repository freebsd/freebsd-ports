https://trac.webkit.org/changeset/244591

--- Source/WebCore/contentextensions/DFACombiner.cpp.orig	2019-02-12 11:21:18 UTC
+++ Source/WebCore/contentextensions/DFACombiner.cpp
@@ -37,7 +37,7 @@ namespace WebCore {
 namespace ContentExtensions {
 
 class DFAMerger {
-    typedef MutableRangeList<char, uint64_t, 128> CombinedTransitionsMutableRangeList;
+    typedef MutableRangeList<signed char, uint64_t, 128> CombinedTransitionsMutableRangeList;
 
     enum class WhichDFA {
         A,
