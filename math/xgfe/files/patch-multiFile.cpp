diff -u multiFile.cpp.orig multiFile.cpp
--- multiFile.cpp.orig	Mon May 18 04:13:18 1998
+++ multiFile.cpp	Thu Oct 30 21:42:04 2003
@@ -23,7 +23,7 @@
    ------------------------------------------------------------------------*/
 
 #include "multiFile.h"
-#include <iostream.h>
+#include <iostream>
 
 
 #define Inherited multiFileData
@@ -86,24 +86,24 @@
   // make sure we actually have files in the combo box
   if (multiFileList->count() > 0)
   {
-    string filename = multiFileList->currentText();
-    string dataSetStart = dataSetStartEdit->text();
-    string dataSetEnd = dataSetEndEdit->text();
-    string dataSetInc = dataSetIncEdit->text();
-    string sampPointInc = pointIncEdit->text();
-    string sampLineInc = lineIncEdit->text();
-    string sampStartPoint = startPointEdit->text();
-    string sampStartLine = startLineEdit->text();
-    string sampEndPoint = endPointEdit->text();
-    string sampEndLine = endLineEdit->text();
-    string xcol = xColumnEdit->text();
-    string ycol = yColumnEdit->text();
-    string zcol = zColumnEdit->text();
-    string format = formatEdit->text();
-    string rawformat = rawFormatEdit->text();
-    string smoothType = interpList->currentText();
-    string style = fileStyleList->currentText();
-    string filter = filterEdit->text();
+    string filename = string(multiFileList->currentText());
+    string dataSetStart = string(dataSetStartEdit->text());
+    string dataSetEnd = string(dataSetEndEdit->text());
+    string dataSetInc = string(dataSetIncEdit->text());
+    string sampPointInc = string(pointIncEdit->text());
+    string sampLineInc = string(lineIncEdit->text());
+    string sampStartPoint = string(startPointEdit->text());
+    string sampStartLine = string(startLineEdit->text());
+    string sampEndPoint = string(endPointEdit->text());
+    string sampEndLine = string(endLineEdit->text());
+    string xcol = string(xColumnEdit->text());
+    string ycol = string(yColumnEdit->text());
+    string zcol = string(zColumnEdit->text());
+    string format = string(formatEdit->text());
+    string rawformat = string(rawFormatEdit->text());
+    string smoothType = string(interpList->currentText());
+    string style = string(fileStyleList->currentText());
+    string filter = string(filterEdit->text());
 
     gnuInt->setMultiFileStyleOption(filename, style);
     gnuInt->setMultiFileDataSetStart(filename,dataSetStart);
@@ -122,7 +122,7 @@
     gnuInt->insertMultiFileRawFormatOption(filename, rawformat);
     gnuInt->setMultiFileSmoothType(filename,smoothType);
 
-    string title = legendTitleEdit->text();
+    string title = string(legendTitleEdit->text());
     gnuInt->setMultiFileLegendTitle(filename, title);
 
     if (legendTitleDefaultButton->isChecked() == TRUE)
@@ -165,7 +165,7 @@
   if (multiFileList->count() > 0)
   { 
     // get current file in combo box
-    string filename = multiFileList->currentText();
+    string filename = string(multiFileList->currentText());
     
     int currentItem = multiFileList->currentItem();
     
@@ -235,7 +235,7 @@
 void multiFile::getCurrentOptions()
 {
   // get options for this file
-  string filename = multiFileList->currentText();
+  string filename = string(multiFileList->currentText());
   string dataSetStart = gnuInt->getMultiFileDataSetStart(filename);
   string dataSetEnd = gnuInt->getMultiFileDataSetEnd(filename);
   string dataSetInc = gnuInt->getMultiFileDataSetIncrement(filename);
