--- examples/markup/parser.cc.orig	Sat Mar 15 17:28:24 2003
+++ examples/markup/parser.cc	Sat Mar 15 17:31:58 2003
@@ -19,7 +19,6 @@
 #include <iomanip>
 #include <iostream>
 
-
 namespace
 {
 
@@ -115,7 +114,7 @@
 void DumpParser::indent()
 {
   if(parse_depth_ > 0)
-    std::cout << std::setw(4 * parse_depth_) << std::right << ' ';
+    std::cout << std::setw(4 * parse_depth_) << std::ios::right << ' ';
 }
 
 } // anonymous namespace
