--- core/src/zxing/DecodeHints.cpp.orig	2016-11-10 14:45:28 UTC
+++ core/src/zxing/DecodeHints.cpp
@@ -29,7 +29,7 @@ using zxing::DecodeHints;
 // VC++
 using zxing::BarcodeFormat;
 
-// const DecodeHintType DecodeHints::CHARACTER_SET;
+const DecodeHintType DecodeHints::CHARACTER_SET;
 
 const DecodeHints DecodeHints::PRODUCT_HINT(
   UPC_A_HINT |
