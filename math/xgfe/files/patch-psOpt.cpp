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
+  string mode = string(modeList->currentText());
+  string color = string(colorList->currentText());
+  string dashed = string(dashedList->currentText());
+  string enhanced = string(enhancedList->currentText());
+  string fontName = string(fontNameEdit->text());
+  string fontSize = string(fontSizeEdit->text());
+  string hSize = string(horizSize->text());
+  string vSize = string(vertSize->text());
 
   gnuInt->setTermPSmode(mode);
   gnuInt->setTermPScolor(color);
