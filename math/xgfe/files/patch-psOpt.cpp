diff -u psOpt.cpp.orig psOpt.cpp
--- psOpt.cpp.orig	Tue May 19 05:39:02 1998
+++ psOpt.cpp	Thu Oct 30 21:42:04 2003
@@ -88,14 +88,14 @@
 
 void psOpt::setTerm()
 {
-  string mode = modeList->currentText();
-  string color = colorList->currentText();
-  string dashed = dashedList->currentText();
-  string enhanced = enhancedList->currentText();
-  string fontName = fontNameEdit->text();
-  string fontSize = fontSizeEdit->text();
-  string hSize = horizSize->text();
-  string vSize = vertSize->text();
+  string mode = modeList->currentText().ascii();
+  string color = colorList->currentText().ascii();
+  string dashed = dashedList->currentText().ascii();
+  string enhanced = enhancedList->currentText().ascii();
+  string fontName = fontNameEdit->text().ascii();
+  string fontSize = fontSizeEdit->text().ascii();
+  string hSize = horizSize->text().ascii();
+  string vSize = vertSize->text().ascii();
 
   gnuInt->setTermPSmode(mode);
   gnuInt->setTermPScolor(color);
