diff -u xgfeMain.cpp.orig xgfeMain.cpp
--- xgfeMain.cpp.orig	Wed Sep 30 04:26:25 1998
+++ xgfeMain.cpp	Thu Oct 30 21:42:04 2003
@@ -62,40 +62,40 @@
     gnuInt->setFuncPlotType("splot");
 
   // save filename
-  gnuInt->setPlotFilename(filenameEdit->text());
+  gnuInt->setPlotFilename(string(filenameEdit->text()));
 
   // save function
-  gnuInt->setPlotFunction(functionEdit->text());
+  gnuInt->setPlotFunction(string(functionEdit->text()));
   
   // save x and y variable names
-  gnuInt->setXVariableName(varX->text());
-  gnuInt->setYVariableName(varY->text());
+  gnuInt->setXVariableName(string(varX->text()));
+  gnuInt->setYVariableName(string(varY->text()));
 
   // save x,y,z ranges
-  gnuInt->setXRangeStart(xStart->text());
-  gnuInt->setXRangeEnd(xEnd->text());
-  gnuInt->setYRangeStart(yStart->text());
-  gnuInt->setYRangeEnd(yEnd->text());
-  gnuInt->setZRangeStart(zStart->text());
-  gnuInt->setZRangeEnd(zEnd->text());
+  gnuInt->setXRangeStart(string(xStart->text()));
+  gnuInt->setXRangeEnd(string(xEnd->text()));
+  gnuInt->setYRangeStart(string(yStart->text()));
+  gnuInt->setYRangeEnd(string(yEnd->text()));
+  gnuInt->setZRangeStart(string(zStart->text()));
+  gnuInt->setZRangeEnd(string(zEnd->text()));
   
   // set x,y,z axis labels
-  gnuInt->setXlabel(xLabel->text());
-  gnuInt->setXOffset_X(XLabelOffset_X->text());
-  gnuInt->setXOffset_Y(XLabelOffset_Y->text());
-  
-  gnuInt->setYlabel(yLabel->text());
-  gnuInt->setYOffset_X(YLabelOffset_X->text());
-  gnuInt->setYOffset_Y(YLabelOffset_Y->text());
-
-  gnuInt->setZlabel(zLabel->text());
-  gnuInt->setZOffset_X(ZLabelOffset_X->text());
-  gnuInt->setZOffset_Y(ZLabelOffset_Y->text());
+  gnuInt->setXlabel(string(xLabel->text()));
+  gnuInt->setXOffset_X(string(XLabelOffset_X->text()));
+  gnuInt->setXOffset_Y(string(XLabelOffset_Y->text()));
+  
+  gnuInt->setYlabel(string(yLabel->text()));
+  gnuInt->setYOffset_X(string(YLabelOffset_X->text()));
+  gnuInt->setYOffset_Y(string(YLabelOffset_Y->text()));
+
+  gnuInt->setZlabel(string(zLabel->text()));
+  gnuInt->setZOffset_X(string(ZLabelOffset_X->text()));
+  gnuInt->setZOffset_Y(string(ZLabelOffset_Y->text()));
   
   // save title
-  gnuInt->setTitle(titleLabel->text());
-  gnuInt->setTitleOffset_X(titleOffset_X->text());
-  gnuInt->setTitleOffset_Y(titleOffset_Y->text());
+  gnuInt->setTitle(string(titleLabel->text()));
+  gnuInt->setTitleOffset_X(string(titleOffset_X->text()));
+  gnuInt->setTitleOffset_Y(string(titleOffset_Y->text()));
 
   // filename option is checked
   if (filenameCB->isChecked() == TRUE)
@@ -130,30 +130,30 @@
   gnuInt->setReplotFlag(1); // set replot flag to true
 
   // save filename
-  gnuInt->setPlotFilename(filenameEdit->text());
+  gnuInt->setPlotFilename(string(filenameEdit->text()));
 
   // save function
-  gnuInt->setPlotFunction(functionEdit->text());
+  gnuInt->setPlotFunction(string(functionEdit->text()));
   
   // don't set ranges because they can't be reset in a replot
   
   // set x,y,z axis labels
-  gnuInt->setXlabel(xLabel->text());
-  gnuInt->setXOffset_X(XLabelOffset_X->text());
-  gnuInt->setXOffset_Y(XLabelOffset_Y->text());
-  
-  gnuInt->setYlabel(yLabel->text());
-  gnuInt->setYOffset_X(YLabelOffset_X->text());
-  gnuInt->setYOffset_Y(YLabelOffset_Y->text());
-
-  gnuInt->setZlabel(zLabel->text());
-  gnuInt->setZOffset_X(ZLabelOffset_X->text());
-  gnuInt->setZOffset_Y(ZLabelOffset_Y->text());
+  gnuInt->setXlabel(string(xLabel->text()));
+  gnuInt->setXOffset_X(string(XLabelOffset_X->text()));
+  gnuInt->setXOffset_Y(string(XLabelOffset_Y->text()));
+  
+  gnuInt->setYlabel(string(yLabel->text()));
+  gnuInt->setYOffset_X(string(YLabelOffset_X->text()));
+  gnuInt->setYOffset_Y(string(YLabelOffset_Y->text()));
+
+  gnuInt->setZlabel(string(zLabel->text()));
+  gnuInt->setZOffset_X(string(ZLabelOffset_X->text()));
+  gnuInt->setZOffset_Y(string(ZLabelOffset_Y->text()));
   
   // save title
-  gnuInt->setTitle(titleLabel->text());
-  gnuInt->setTitleOffset_X(titleOffset_X->text());
-  gnuInt->setTitleOffset_Y(titleOffset_Y->text());
+  gnuInt->setTitle(string(titleLabel->text()));
+  gnuInt->setTitleOffset_X(string(titleOffset_X->text()));
+  gnuInt->setTitleOffset_Y(string(titleOffset_Y->text()));
 
   if (filenameCB->isChecked() == TRUE) // filename option is checked
   {
