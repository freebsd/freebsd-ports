diff -u fileOptions.cpp.orig fileOptions.cpp
--- fileOptions.cpp.orig	Sat May  9 02:48:15 1998
+++ fileOptions.cpp	Thu Oct 30 21:42:04 2003
@@ -96,21 +96,21 @@
 
 void fileOptions::setFormat()
 {
-  string dataSetStart = dataSetStartEdit->text();
-  string dataSetEnd = dataSetEndEdit->text();
-  string dataSetInc = dataSetIncEdit->text();
-  string sampPointInc = pointIncEdit->text();
-  string sampLineInc = lineIncEdit->text();
-  string sampStartPoint = startPointEdit->text();
-  string sampStartLine = startLineEdit->text();
-  string sampEndPoint = endPointEdit->text();
-  string sampEndLine = endLineEdit->text();
-  string xCol = xColumnEdit->text();
-  string yCol = yColumnEdit->text();
-  string zCol = zColumnEdit->text();
-  string format = formatEdit->text();
-  string rawFormat = rawFormatEdit->text();
-  string smoothType = interpList->currentText();
+  string dataSetStart = string(dataSetStartEdit->text());
+  string dataSetEnd = string(dataSetEndEdit->text());
+  string dataSetInc = string(dataSetIncEdit->text());
+  string sampPointInc = string(pointIncEdit->text());
+  string sampLineInc = string(lineIncEdit->text());
+  string sampStartPoint = string(startPointEdit->text());
+  string sampStartLine = string(startLineEdit->text());
+  string sampEndPoint = string(endPointEdit->text());
+  string sampEndLine = string(endLineEdit->text());
+  string xCol = string(xColumnEdit->text());
+  string yCol = string(yColumnEdit->text());
+  string zCol = string(zColumnEdit->text());
+  string format = string(formatEdit->text());
+  string rawFormat = string(rawFormatEdit->text());
+  string smoothType = string(interpList->currentText());
 
   gnuInt->setFileDataSetStart(dataSetStart);
   gnuInt->setFileDataSetEnd(dataSetEnd);
