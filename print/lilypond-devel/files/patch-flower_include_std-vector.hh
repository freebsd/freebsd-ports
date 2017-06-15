--- flower/include/std-vector.hh.orig	2017-02-26 12:08:59 UTC
+++ flower/include/std-vector.hh
@@ -212,6 +212,6 @@ junk_pointers (vector<T> &v)
 vector<string> string_split (string str, char c);
 string string_join (vector<string> const &strs, const string &infix);
 
-#define iterof(i,s) typeof((s).begin()) i((s).begin())
+#define iterof(i,s) auto i = ((s).begin())
 
 #endif /* STD_VECTOR_HH */
