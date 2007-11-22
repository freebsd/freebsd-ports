--- search/WordKeySemantic.cc.orig	2007-11-22 11:42:09.000000000 +0100
+++ search/WordKeySemantic.cc	2007-11-22 11:42:58.000000000 +0100
@@ -134,7 +134,7 @@
   }
 }
 
-int WordKeySemantic::LocationCompare(const WordKey& expected, const WordKey& actual, int proximity = 0)
+int WordKeySemantic::LocationCompare(const WordKey& expected, const WordKey& actual, int proximity)
 {
   int ret = 1;
 
