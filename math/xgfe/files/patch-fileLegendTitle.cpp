diff -u fileLegendTitle.cpp.orig fileLegendTitle.cpp
--- fileLegendTitle.cpp.orig	Sat Mar 21 04:24:41 1998
+++ fileLegendTitle.cpp	Thu Oct 30 21:42:04 2003
@@ -45,7 +45,7 @@
 
 void fileLegendTitle::setFileLegendTitleOK()
 {
-  string title = fileLegendTitleEdit->text();
+  string title = fileLegendTitleEdit->text().ascii();
   gnuInt->setFileLegendTitle(title);
 
   if (defaultCButton->isChecked() == TRUE)
