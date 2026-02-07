--- src/core/CLucene/index/IndexWriter.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/index/IndexWriter.cpp	2014-06-24 19:10:36.000000000 -0400
@@ -53,7 +53,6 @@
 
 DEFINE_MUTEX(IndexWriter::MESSAGE_ID_LOCK)
 int32_t IndexWriter::MESSAGE_ID = 0;
-const int32_t IndexWriter::MAX_TERM_LENGTH = DocumentsWriter::MAX_TERM_LENGTH;
 
 class IndexWriter::Internal{
 public:
@@ -814,7 +813,7 @@
   ensureOpen();
 
   if (maxNumSegments < 1)
-    _CLTHROWA(CL_ERR_IllegalArgument, "maxNumSegments must be >= 1; got " + maxNumSegments);
+    _CLTHROWA(CL_ERR_IllegalArgument, (string("maxNumSegments must be >= 1; got ") + Misc::toString(maxNumSegments)).c_str());
 
   if (infoStream != NULL)
     message("optimize: index now " + segString());
@@ -1392,7 +1391,7 @@
     // Check if the doc stores must be separately flushed
     // because other segments, besides the one we are about
     // to flush, reference it
-    if (_flushDocStores && (!flushDocs || !docWriter->getSegment().compare(docWriter->getDocStoreSegment())==0 )) {
+    if (_flushDocStores && (!flushDocs || docWriter->getSegment().compare(docWriter->getDocStoreSegment()) != 0)) {
       // We must separately flush the doc store
       if (infoStream != NULL)
         message("  flush shared docStore segment " + docStoreSegment);
@@ -1631,7 +1630,7 @@
         // Load deletes present @ start of merge, for this segment:
         BitVector previousDeletes(previousInfo->dir, previousInfo->getDelFileName().c_str());
 
-        if (!currentInfo->getDelFileName().compare(previousInfo->getDelFileName())==0 ){
+        if (currentInfo->getDelFileName().compare(previousInfo->getDelFileName()) != 0) {
           // This means this segment has had new deletes
           // committed since we started the merge, so we
           // must merge them:
@@ -1928,7 +1927,7 @@
       mergeDocStores = true;
     else if (lastDocStoreSegment.empty())
       lastDocStoreSegment = docStoreSegment;
-    else if (!lastDocStoreSegment.compare(docStoreSegment)==0 )
+    else if (lastDocStoreSegment.compare(docStoreSegment) != 0)
       mergeDocStores = true;
 
     // Segments' docScoreOffsets must be in-order,
