--- ./src/GAfit.cpp.orig	2011-06-04 02:11:35.000000000 +0200
+++ ./src/GAfit.cpp	2014-04-08 14:57:25.531599033 +0200
@@ -346,7 +346,7 @@
 struct Remainder_and_ptr {
     int ind;
     realt r;
-    bool operator< (const Remainder_and_ptr &b) {
+    bool operator< (const Remainder_and_ptr &b) const {
         return r < b.r;
     }
 };
