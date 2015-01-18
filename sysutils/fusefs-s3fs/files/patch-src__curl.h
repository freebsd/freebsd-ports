--- src/curl.h.orig	2015-01-18 22:44:00.232344078 +0800
+++ src/curl.h	2015-01-18 22:44:37.736341674 +0800
@@ -85,7 +85,7 @@ struct filepart
 // for progress
 struct case_insensitive_compare_func
 {
-  bool operator()(const std::string& a, const std::string& b){
+  bool operator()(const std::string& a, const std::string& b) const {
     return strcasecmp(a.c_str(), b.c_str()) < 0;
   }
 };
