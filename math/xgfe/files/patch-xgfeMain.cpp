--- xgfeMain.cpp.orig	Wed Sep 30 04:26:25 1998
+++ xgfeMain.cpp	Thu Oct 30 21:42:04 2003
@@ -62,40 +62,40 @@
     gnuInt->setFuncPlotType("splot");
 
   // save filename
-  gnuInt->setPlotFilename(filenameEdit->text());
+  gnuInt->setPlotFilename(string(filenameEdit->text().ascii()));
 
   // save function
-  gnuInt->setPlotFunction(functionEdit->text());
+  gnuInt->setPlotFunction(string(functionEdit->text().ascii()));
   
   // save x and y variable names
-  gnuInt->setXVariableName(varX->text());
-  gnuInt->setYVariableName(varY->text());
+  gnuInt->setXVariableName(string(varX->text().ascii()));
+  gnuInt->setYVariableName(string(varY->text().ascii()));
 
   // save x,y,z ranges
-  gnuInt->setXRangeStart(xStart->text());
-  gnuInt->setXRangeEnd(xEnd->text());
-  gnuInt->setYRangeStart(yStart->text());
-  gnuInt->setYRangeEnd(yEnd->text());
-  gnuInt->setZRangeStart(zStart->text());
-  gnuInt->setZRangeEnd(zEnd->text());
+  gnuInt->setXRangeStart(string(xStart->text().ascii()));
+  gnuInt->setXRangeEnd(string(xEnd->text().ascii()));
+  gnuInt->setYRangeStart(string(yStart->text().ascii()));
+  gnuInt->setYRangeEnd(string(yEnd->text().ascii()));
+  gnuInt->setZRangeStart(string(zStart->text().ascii()));
+  gnuInt->setZRangeEnd(string(zEnd->text().ascii()));
   
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
+  gnuInt->setXlabel(string(xLabel->text().ascii()));
+  gnuInt->setXOffset_X(string(XLabelOffset_X->text().ascii()));
+  gnuInt->setXOffset_Y(string(XLabelOffset_Y->text().ascii()));
+  
+  gnuInt->setYlabel(string(yLabel->text().ascii()));
+  gnuInt->setYOffset_X(string(YLabelOffset_X->text().ascii()));
+  gnuInt->setYOffset_Y(string(YLabelOffset_Y->text().ascii()));
+
+  gnuInt->setZlabel(string(zLabel->text().ascii()));
+  gnuInt->setZOffset_X(string(ZLabelOffset_X->text().ascii()));
+  gnuInt->setZOffset_Y(string(ZLabelOffset_Y->text().ascii()));
   
   // save title
-  gnuInt->setTitle(titleLabel->text());
-  gnuInt->setTitleOffset_X(titleOffset_X->text());
-  gnuInt->setTitleOffset_Y(titleOffset_Y->text());
+  gnuInt->setTitle(string(titleLabel->text().ascii()));
+  gnuInt->setTitleOffset_X(string(titleOffset_X->text().ascii()));
+  gnuInt->setTitleOffset_Y(string(titleOffset_Y->text().ascii()));
 
   // filename option is checked
   if (filenameCB->isChecked() == TRUE)
@@ -130,30 +130,30 @@
   gnuInt->setReplotFlag(1); // set replot flag to true
 
   // save filename
-  gnuInt->setPlotFilename(filenameEdit->text());
+  gnuInt->setPlotFilename(string(filenameEdit->text().ascii()));
 
   // save function
-  gnuInt->setPlotFunction(functionEdit->text());
+  gnuInt->setPlotFunction(string(functionEdit->text().ascii()));
   
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
+  gnuInt->setXlabel(string(xLabel->text().ascii()));
+  gnuInt->setXOffset_X(string(XLabelOffset_X->text().ascii()));
+  gnuInt->setXOffset_Y(string(XLabelOffset_Y->text().ascii()));
+  
+  gnuInt->setYlabel(string(yLabel->text().ascii()));
+  gnuInt->setYOffset_X(string(YLabelOffset_X->text().ascii()));
+  gnuInt->setYOffset_Y(string(YLabelOffset_Y->text().ascii()));
+
+  gnuInt->setZlabel(string(zLabel->text().ascii()));
+  gnuInt->setZOffset_X(string(ZLabelOffset_X->text().ascii()));
+  gnuInt->setZOffset_Y(string(ZLabelOffset_Y->text().ascii()));
   
   // save title
-  gnuInt->setTitle(titleLabel->text());
-  gnuInt->setTitleOffset_X(titleOffset_X->text());
-  gnuInt->setTitleOffset_Y(titleOffset_Y->text());
+  gnuInt->setTitle(string(titleLabel->text().ascii()));
+  gnuInt->setTitleOffset_X(string(titleOffset_X->text().ascii()));
+  gnuInt->setTitleOffset_Y(string(titleOffset_Y->text().ascii()));
 
   if (filenameCB->isChecked() == TRUE) // filename option is checked
   {
@@ -227,7 +227,7 @@
   {
     filenameEdit->setText(filename); // set label to filename
     filenameCB->setChecked(TRUE);     // set filename checkbox
-    temp = filename;
+    temp = filename.ascii();
     gnuInt->setPlotFilename(temp);
   }
   
@@ -242,7 +242,7 @@
   
   if (!saveFile.isEmpty())
   {
-    temp = saveFile;
+    temp = saveFile.ascii();
     gnuInt->setGnuFileSave(temp);
     gnuInt->doSave();
   }
@@ -257,7 +257,7 @@
 
   if (!loadFile.isEmpty())
   {
-    temp = loadFile;
+    temp = loadFile.ascii();
     gnuInt->setGnuFileLoad(temp);
     gnuInt->doLoad();
   }
@@ -272,7 +272,7 @@
   
   if (!saveFile.isEmpty())
   {
-    temp = saveFile;
+    temp = saveFile.ascii();
     gnuInt->savePlotData(temp);
   }
 }
@@ -286,7 +286,7 @@
 
   if (!loadFile.isEmpty())
   {
-    temp = loadFile;
+    temp = loadFile.ascii();
     gnuInt->loadPlotData(temp);
 
     // get options and set GUI
