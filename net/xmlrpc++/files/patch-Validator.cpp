--- test/Validator.cpp.orig	Thu Nov 13 14:47:39 2003
+++ test/Validator.cpp	Thu Nov 13 14:47:56 2003
@@ -137,7 +137,7 @@
   {
     std::cerr << "ModerateSizeArrayCheck\n";
     std::string s = params[0][0];
-    s += params[0][params[0].size()-1];
+    s += (std::string)params[0][params[0].size()-1];
     result = s;
   }
 } moderateSizeArrayCheck(&s);
