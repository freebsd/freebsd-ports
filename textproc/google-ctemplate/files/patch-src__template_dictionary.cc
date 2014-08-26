--- ./src/template_dictionary.cc.orig	2014-08-26 12:36:15.829733992 -0400
+++ ./src/template_dictionary.cc	2014-08-26 12:36:37.238772992 -0400
@@ -861,7 +861,7 @@
 
   string GetDictNum(size_t index, size_t size) const {
     char buf[64];   // big enough for two ints
-    snprintf(buf, sizeof(buf), "%" PRIuS" of %" PRIuS, index, size);
+    snprintf(buf, sizeof(buf), "%" PRIuS " of %" PRIuS, index, size);
     return buf;
   }
 
