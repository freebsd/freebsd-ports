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
+  string dataSetStart = dataSetStartEdit->text().ascii();
+  string dataSetEnd = dataSetEndEdit->text().ascii();
+  string dataSetInc = dataSetIncEdit->text().ascii();
+  string sampPointInc = pointIncEdit->text().ascii();
+  string sampLineInc = lineIncEdit->text().ascii();
+  string sampStartPoint = startPointEdit->text().ascii();
+  string sampStartLine = startLineEdit->text().ascii();
+  string sampEndPoint = endPointEdit->text().ascii();
+  string sampEndLine = endLineEdit->text().ascii();
+  string xCol = xColumnEdit->text().ascii();
+  string yCol = yColumnEdit->text().ascii();
+  string zCol = zColumnEdit->text().ascii();
+  string format = formatEdit->text().ascii();
+  string rawFormat = rawFormatEdit->text().ascii();
+  string smoothType = interpList->currentText().ascii();
 
   gnuInt->setFileDataSetStart(dataSetStart);
   gnuInt->setFileDataSetEnd(dataSetEnd);
