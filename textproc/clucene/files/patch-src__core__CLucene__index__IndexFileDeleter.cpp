--- src/core/CLucene/index/IndexFileDeleter.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/index/IndexFileDeleter.cpp	2014-06-24 19:06:58.000000000 -0400
@@ -129,7 +129,7 @@
 
 	  string& fileName = files.at(i);
 
-    if (filter->accept(NULL, fileName.c_str()) && !fileName.compare(IndexFileNames::SEGMENTS_GEN) == 0) {
+    if (filter->accept(NULL, fileName.c_str()) && fileName.compare(IndexFileNames::SEGMENTS_GEN) != 0) {
 
 	    // Add this file to refCounts with initial count 0:
 	    getRefCount(fileName.c_str());
