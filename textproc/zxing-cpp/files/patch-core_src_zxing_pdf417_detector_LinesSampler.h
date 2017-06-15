--- core/src/zxing/pdf417/detector/LinesSampler.h.orig	2016-11-14 22:55:07 UTC
+++ core/src/zxing/pdf417/detector/LinesSampler.h
@@ -28,12 +28,12 @@ namespace detector {
 
 class LinesSampler {
 protected:
-  static const int MODULES_IN_SYMBOL = 17;
-  static const int BARS_IN_SYMBOL = 8;
-  static const int POSSIBLE_SYMBOLS = 2787;
+  static const int MODULES_IN_SYMBOL;
+  static const int BARS_IN_SYMBOL;
+  static const int POSSIBLE_SYMBOLS;
   static const std::vector<float> RATIOS_TABLE;
   static std::vector<float> init_ratios_table();
-  static const int BARCODE_START_OFFSET = 2;
+  static const int BARCODE_START_OFFSET;
 
   Ref<BitMatrix> linesMatrix_;
   int symbolsPerLine_;
