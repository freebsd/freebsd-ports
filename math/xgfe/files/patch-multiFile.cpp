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
+    string filename = multiFileList->currentText().ascii();
+    string dataSetStart = dataSetStartEdit->text().ascii();
+    string dataSetEnd = dataSetEndEdit->text().ascii();
+    string dataSetInc = dataSetIncEdit->text().ascii();
+    string sampPointInc = pointIncEdit->text().ascii();
+    string sampLineInc = lineIncEdit->text().ascii();
+    string sampStartPoint = startPointEdit->text().ascii();
+    string sampStartLine = startLineEdit->text().ascii();
+    string sampEndPoint = endPointEdit->text().ascii();
+    string sampEndLine = endLineEdit->text().ascii();
+    string xcol = xColumnEdit->text().ascii();
+    string ycol = yColumnEdit->text().ascii();
+    string zcol = zColumnEdit->text().ascii();
+    string format = formatEdit->text().ascii();
+    string rawformat = rawFormatEdit->text().ascii();
+    string smoothType = interpList->currentText().ascii();
+    string style = fileStyleList->currentText().ascii();
+    string filter = filterEdit->text().ascii();
 
     gnuInt->setMultiFileStyleOption(filename, style);
     gnuInt->setMultiFileDataSetStart(filename,dataSetStart);
@@ -122,7 +122,7 @@
     gnuInt->insertMultiFileRawFormatOption(filename, rawformat);
     gnuInt->setMultiFileSmoothType(filename,smoothType);
 
-    string title = legendTitleEdit->text();
+    string title = legendTitleEdit->text().ascii();
     gnuInt->setMultiFileLegendTitle(filename, title);
 
     if (legendTitleDefaultButton->isChecked() == TRUE)
@@ -150,7 +150,7 @@
   
   if ( !filename.isNull() )
   {
-    temp = filename;
+    temp = filename.ascii();
 
     multiFileList->insertItem(filename,0);
     gnuInt->insertMultiFileNew(temp);
@@ -165,7 +165,7 @@
   if (multiFileList->count() > 0)
   { 
     // get current file in combo box
-    string filename = multiFileList->currentText();
+    string filename = multiFileList->currentText().ascii();
     
     int currentItem = multiFileList->currentItem();
     
@@ -235,7 +235,7 @@
 void multiFile::getCurrentOptions()
 {
   // get options for this file
-  string filename = multiFileList->currentText();
+  string filename = multiFileList->currentText().ascii();
   string dataSetStart = gnuInt->getMultiFileDataSetStart(filename);
   string dataSetEnd = gnuInt->getMultiFileDataSetEnd(filename);
   string dataSetInc = gnuInt->getMultiFileDataSetIncrement(filename);
