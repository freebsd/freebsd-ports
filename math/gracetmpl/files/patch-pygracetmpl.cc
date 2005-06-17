--- python/src/pygracetmpl.cc.orig	Mon Sep 27 16:59:49 2004
+++ python/src/pygracetmpl.cc	Sat Jun 18 00:44:43 2005
@@ -1,15 +1,15 @@
 #include <gracetmpl.h>
 
+#include <string.h>
+#include <complex>
+#include <set>
+
 /* python headers */
 #include <Python.h>
 /* numarray headers */
 #include <numarray/numarray.h>
 #include <numarray/arrayobject.h>
 
-#include <string.h>
-#include <complex>
-#include <set>
-
 /********************************************************/
 /******************* graceTMPL.data type ***************/
 /********************************************************/
@@ -159,6 +159,7 @@
   PyArrayObject *dataArray = 0;
   GraceTMPL::Data *newData = 0;
   graceTMPL_dataObject *dataObject = 0;
+  int cols, rows;
   
   if (!PyArg_ParseTuple(args, "sO:graceTMPL.graph.addData(name, dataArray)",
 			&name, &oDataArray)){
@@ -178,12 +179,12 @@
 		    "data array has to have at least dimension 2 in first axis");
     return NULL;
   }
-  PyArray_INCREF(dataArray);
-  int cols = dataArray->dimensions[0];
-  int rows = dataArray->dimensions[1];
+  XXX_PyArray_INCREF(dataArray);
+  cols = dataArray->dimensions[0];
+  rows = dataArray->dimensions[1];
   if(cols > 4)
     cols = 4;
-  double **data = new (double *)[cols];
+  double **data = new double *[cols];
   for(int c = 0; c < cols; ++c){
     data[c] = new double[rows];
     for(int r = 0; r < rows; ++r)
@@ -191,7 +192,7 @@
 			       c * dataArray->strides[0] +
 			       r * dataArray->strides[1]);
   }
-  PyArray_XDECREF(dataArray);
+  XXX_PyArray_XDECREF(dataArray);
   switch(cols){
   case 2:
     newData = new GraceTMPL::Data(std::string(name), rows,
