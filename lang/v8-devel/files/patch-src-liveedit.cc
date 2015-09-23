--- src/liveedit.cc.orig	2014-06-03 08:52:11 UTC
+++ src/liveedit.cc
@@ -174,7 +174,7 @@ class Differencer {
 
   static const int kDirectionSizeBits = 2;
   static const int kDirectionMask = (1 << kDirectionSizeBits) - 1;
-  static const int kEmptyCellValue = -1 << kDirectionSizeBits;
+  static const int kEmptyCellValue = -(1 << kDirectionSizeBits);
 
   // This method only holds static assert statement (unfortunately you cannot
   // place one in class scope).
