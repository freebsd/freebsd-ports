--- python/src/pygracetmpl.cc.orig	Sat Oct 12 05:12:57 2002
+++ python/src/pygracetmpl.cc	Sun Dec  5 12:35:53 2004
@@ -1,11 +1,10 @@
 #include <gracetmpl.h>
 
-#include <Python.h>
-#include <Numeric/arrayobject.h> /* numerical python header */
-
 #include <string.h>
 #include <complex>
 #include <set>
+#include <Python.h>
+#include <Numeric/arrayobject.h> /* numerical python header */
 
 /********************************************************/
 /******************* graceTMPL.data type ***************/
@@ -179,7 +178,7 @@
   int rows = dataArray->dimensions[1];
   if(cols > 4)
     cols = 4;
-  double **data = new (double *)[cols];
+  double **data = new double *[cols];
   for(int c = 0; c < cols; ++c){
     data[c] = new double[rows];
     for(int r = 0; r < rows; ++r)
