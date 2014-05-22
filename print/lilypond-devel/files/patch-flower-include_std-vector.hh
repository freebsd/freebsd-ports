--- flower/include/std-vector.hh.orig	2014-05-05 10:25:02.000000000 +0200
+++ flower/include/std-vector.hh	2014-05-05 10:28:54.000000000 +0200
@@ -261,6 +261,6 @@
 vector<string> string_split (string str, char c);
 string string_join (vector<string> const &strs, const string &infix);
 
-#define iterof(i,s) typeof((s).begin()) i((s).begin())
+#define iterof(i,s) auto i = ((s).begin())
 
 #endif /* STD_VECTOR_HH */
