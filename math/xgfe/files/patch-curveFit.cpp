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
+  string functionName = string(functionNameEdit->text());
+  string functionValue = string(functionValueEdit->text());
+  string dataFile = string(dataFileEdit->text());
+  string varXRangeName = string(varXRangeNameEdit->text());
+  string varXRangeMin = string(varXRangeMinEdit->text());
+  string varXRangeMax = string(varXRangeMaxEdit->text());
+  string varYRangeName = string(varYRangeNameEdit->text());
+  string varYRangeMin = string(varYRangeMinEdit->text());
+  string varYRangeMax = string(varYRangeMaxEdit->text());
+  string paramFile = string(paramFileEdit->text());
 
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
+  string paramCSL = string(paramCSLEdit->text());
+  string fitLimit = string(fitLimitEdit->text());
+  string fitMaxIter = string(fitMaxIterEdit->text());
+  string dataSetStart = string(dataSetStartEdit->text());
+  string dataSetEnd = string(dataSetEndEdit->text());
+  string dataSetInc = string(dataSetIncEdit->text());
+  string pointInc = string(pointIncEdit->text());
+  string lineInc = string(lineIncEdit->text());
+  string startPoint = string(startPointEdit->text());
+  string startLine = string(startLineEdit->text());
+  string endPoint = string(endPointEdit->text());
+  string endLine = string(endLineEdit->text());
+  string xColumn = string(xColumnEdit->text());
+  string yColumn = string(yColumnEdit->text());
+  string zColumn = string(zColumnEdit->text());
+  string format = string(formatEdit->text());
+  string rawFormat = string(rawFormatEdit->text());
 
   // set options
 
