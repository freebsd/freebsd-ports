https://trac.webkit.org/changeset/244591

--- Source/WebCore/contentextensions/NFAToDFA.cpp.orig	2019-02-12 11:21:18 UTC
+++ Source/WebCore/contentextensions/NFAToDFA.cpp
@@ -41,9 +41,9 @@ namespace WebCore {
 
 namespace ContentExtensions {
 
-typedef MutableRange<char, NFANodeIndexSet> NFANodeRange;
-typedef MutableRangeList<char, NFANodeIndexSet> NFANodeRangeList;
-typedef MutableRangeList<char, NFANodeIndexSet, 128> PreallocatedNFANodeRangeList;
+typedef MutableRange<signed char, NFANodeIndexSet> NFANodeRange;
+typedef MutableRangeList<signed char, NFANodeIndexSet> NFANodeRangeList;
+typedef MutableRangeList<signed char, NFANodeIndexSet, 128> PreallocatedNFANodeRangeList;
 typedef Vector<uint32_t, 0, ContentExtensionsOverflowHandler> UniqueNodeList;
 typedef Vector<UniqueNodeList, 0, ContentExtensionsOverflowHandler> NFANodeClosures;
 
