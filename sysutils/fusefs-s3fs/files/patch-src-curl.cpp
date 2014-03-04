--- src/curl.cpp.orig	2014-03-04 22:16:31.000000000 +0100
+++ src/curl.cpp	2014-03-04 22:16:41.000000000 +0100
@@ -53,7 +53,7 @@
 // Typedef
 //-------------------------------------------------------------------
 struct case_insensitive_compare_func {
-  bool operator ()(const string &a, const string &b) {
+  bool operator ()(const string &a, const string &b) const {
     return strcasecmp(a.c_str(), b.c_str()) < 0;
   }
 };
