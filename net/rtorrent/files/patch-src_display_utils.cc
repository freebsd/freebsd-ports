--- src/display/utils.cc.orig
+++ src/display/utils.cc
@@ -58,7 +58,7 @@
 
 std::string
 print_hhmmss(utils::Timer t) {
-  std::tm *u = std::localtime(&t.tval().tv_sec);
+  std::tm *u = std::localtime((const time_t *)&t.tval().tv_sec);
   
   if (u == NULL)
     return "inv_time";
