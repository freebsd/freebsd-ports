--- fileFilter.cpp.orig	Mon May 18 04:06:51 1998
+++ fileFilter.cpp	Wed Mar 17 15:29:57 2004
@@ -93,7 +93,7 @@
   else if (doubleQuoteRB->isChecked() == TRUE)
     gnuInt->setFileFilterQuoteChar("double");
   
-  filterCmd += filterEdit->text();
+  filterCmd += filterEdit->text().ascii();
   
   gnuInt->setFileFilter(filterCmd);
 
