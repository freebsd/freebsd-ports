Patch for the obvious bug. Reported to the upstream.

--- modules/base/src/test_utils/compare_files.cc.orig	2018-07-10 05:54:54 UTC
+++ modules/base/src/test_utils/compare_files.cc
@@ -37,8 +37,10 @@ bool compare_files(const String& test, c
   }
   String test_line, gold_line;
   while (true) {
-    bool test_end=std::getline(test_stream, test_line) != 0;
-    bool gold_end=std::getline(gold_stream, gold_line) != 0;
+    std::getline(test_stream, test_line);
+    std::getline(gold_stream, gold_line);
+    bool test_end=test_stream.eof();
+    bool gold_end=gold_stream.eof();
     if (!(test_end || gold_end)) {
       return true;
     }
