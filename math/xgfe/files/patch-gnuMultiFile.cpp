diff -u gnuMultiFile.cpp.orig gnuMultiFile.cpp
--- gnuMultiFile.cpp.orig	Mon May 18 04:11:55 1998
+++ gnuMultiFile.cpp	Thu Oct 30 21:42:04 2003
@@ -31,7 +31,7 @@
 gnuMultiFile::gnuMultiFile()
 {
   // create new filelist
-  fileList = new QDict<gnuPlotFile>(101,TRUE,TRUE); // max 100 elements
+  fileList = new QDict<gnuPlotFile>(101,TRUE); // max 100 elements
   fileList->setAutoDelete(TRUE); // autodelete members when removed
 
   // create new iterator
