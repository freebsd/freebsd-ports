--- core/src/zxing/pdf417/detector/LinesSampler.cpp.orig	2016-11-10 14:45:28 UTC
+++ core/src/zxing/pdf417/detector/LinesSampler.cpp
@@ -75,6 +75,11 @@ VoteResult getValueWithMaxVotes(map<int,
 
 }
 
+const int LinesSampler::MODULES_IN_SYMBOL = 17;
+const int LinesSampler::BARS_IN_SYMBOL = 8;
+const int LinesSampler::POSSIBLE_SYMBOLS = 2787;
+const int LinesSampler::BARCODE_START_OFFSET = 2;
+
 vector<float> LinesSampler::init_ratios_table() {
   // Pre-computes and outputs the symbol ratio table.
   vector<vector<float> > table (BitMatrixParser::SYMBOL_TABLE_LENGTH);
