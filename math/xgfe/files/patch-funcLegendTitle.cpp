diff -u funcLegendTitle.cpp.orig funcLegendTitle.cpp
--- funcLegendTitle.cpp.orig	Sat Mar 21 04:24:42 1998
+++ funcLegendTitle.cpp	Thu Oct 30 21:42:04 2003
@@ -44,7 +44,7 @@
 
 void funcLegendTitle::setFuncLegendTitleOK()
 {
-  string title = funcLegendTitleEdit->text();
+  string title = funcLegendTitleEdit->text().ascii();
   gnuInt->setFuncLegendTitle(title);
 
   if (defaultCButton->isChecked() == TRUE)
