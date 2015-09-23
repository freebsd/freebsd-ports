--- src/liveedit.cc.orig	2013-05-01 12:56:29 UTC
+++ src/liveedit.cc
@@ -203,7 +203,7 @@ class Differencer {
 
   static const int kDirectionSizeBits = 2;
   static const int kDirectionMask = (1 << kDirectionSizeBits) - 1;
-  static const int kEmptyCellValue = -1 << kDirectionSizeBits;
+  static const int kEmptyCellValue = -(1 << kDirectionSizeBits);
 
   // This method only holds static assert statement (unfortunately you cannot
   // place one in class scope).
