diff -u gnuMultiFunc.cpp.orig gnuMultiFunc.cpp
--- gnuMultiFunc.cpp.orig	Sat Mar 21 04:24:44 1998
+++ gnuMultiFunc.cpp	Thu Oct 30 21:42:04 2003
@@ -31,7 +31,7 @@
 gnuMultiFunc::gnuMultiFunc()
 {
   // create new function list
-  funcList = new QDict<gnuPlotFunction>(101,TRUE,TRUE); // max 100 elements
+  funcList = new QDict<gnuPlotFunction>(101,TRUE); // max 100 elements
   funcList->setAutoDelete(TRUE); // autodelete members when removed
 
   // create new iterator
