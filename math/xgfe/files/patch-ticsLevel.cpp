diff -u ticsLevel.cpp.orig ticsLevel.cpp
--- ticsLevel.cpp.orig	Thu Jul 23 04:31:07 1998
+++ ticsLevel.cpp	Thu Oct 30 21:42:04 2003
@@ -55,7 +55,7 @@
 
 void ticsLevel::setTicsLevel()
 {
-  string level = ticsLevelEdit->text();
+  string level = ticsLevelEdit->text().ascii();
 
   gnuInt->setTicsLevel(level);
   
