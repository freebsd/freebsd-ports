diff -u curveFit.cpp.orig curveFit.cpp
--- curveFit.cpp.orig	Mon May 18 04:06:03 1998
+++ curveFit.cpp	Thu Oct 30 21:42:04 2003
@@ -145,16 +145,16 @@
 {
   // get current options
 
-  string functionName = functionNameEdit->text();
-  string functionValue = functionValueEdit->text();
-  string dataFile = dataFileEdit->text();
-  string varXRangeName = varXRangeNameEdit->text();
-  string varXRangeMin = varXRangeMinEdit->text();
-  string varXRangeMax = varXRangeMaxEdit->text();
-  string varYRangeName = varYRangeNameEdit->text();
-  string varYRangeMin = varYRangeMinEdit->text();
-  string varYRangeMax = varYRangeMaxEdit->text();
-  string paramFile = paramFileEdit->text();
+  string functionName = functionNameEdit->text().ascii();
+  string functionValue = functionValueEdit->text().ascii();
+  string dataFile = dataFileEdit->text().ascii();
+  string varXRangeName = varXRangeNameEdit->text().ascii();
+  string varXRangeMin = varXRangeMinEdit->text().ascii();
+  string varXRangeMax = varXRangeMaxEdit->text().ascii();
+  string varYRangeName = varYRangeNameEdit->text().ascii();
+  string varYRangeMin = varYRangeMinEdit->text().ascii();
+  string varYRangeMax = varYRangeMaxEdit->text().ascii();
+  string paramFile = paramFileEdit->text().ascii();
 
   int paramFileFlag;
   int paramCSLFlag;
@@ -171,23 +171,23 @@
     paramCSLFlag = 1;
   }
 
-  string paramCSL = paramCSLEdit->text();
-  string fitLimit = fitLimitEdit->text();
-  string fitMaxIter = fitMaxIterEdit->text();
-  string dataSetStart = dataSetStartEdit->text();
-  string dataSetEnd = dataSetEndEdit->text();
-  string dataSetInc = dataSetIncEdit->text();
-  string pointInc = pointIncEdit->text();
-  string lineInc = lineIncEdit->text();
-  string startPoint = startPointEdit->text();
-  string startLine = startLineEdit->text();
-  string endPoint = endPointEdit->text();
-  string endLine = endLineEdit->text();
-  string xColumn = xColumnEdit->text();
-  string yColumn = yColumnEdit->text();
-  string zColumn = zColumnEdit->text();
-  string format = formatEdit->text();
-  string rawFormat = rawFormatEdit->text();
+  string paramCSL = paramCSLEdit->text().ascii();
+  string fitLimit = fitLimitEdit->text().ascii();
+  string fitMaxIter = fitMaxIterEdit->text().ascii();
+  string dataSetStart = dataSetStartEdit->text().ascii();
+  string dataSetEnd = dataSetEndEdit->text().ascii();
+  string dataSetInc = dataSetIncEdit->text().ascii();
+  string pointInc = pointIncEdit->text().ascii();
+  string lineInc = lineIncEdit->text().ascii();
+  string startPoint = startPointEdit->text().ascii();
+  string startLine = startLineEdit->text().ascii();
+  string endPoint = endPointEdit->text().ascii();
+  string endLine = endLineEdit->text().ascii();
+  string xColumn = xColumnEdit->text().ascii();
+  string yColumn = yColumnEdit->text().ascii();
+  string zColumn = zColumnEdit->text().ascii();
+  string format = formatEdit->text().ascii();
+  string rawFormat = rawFormatEdit->text().ascii();
 
   // set options
 
