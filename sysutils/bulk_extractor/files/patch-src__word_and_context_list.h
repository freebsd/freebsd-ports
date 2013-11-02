--- ./src/word_and_context_list.h.orig	2012-12-12 15:36:14.000000000 +0000
+++ ./src/word_and_context_list.h	2013-10-19 13:09:32.000000000 +0000
@@ -29,8 +29,18 @@
  * Typically this is used for stop lists and alert lists. 
  */
 
+#ifdef __clang__
+#if __has_include(<unordered_set>)
+#define HAVE_CXX11_UNORDERED_SET 1
+#endif
+#endif
+#ifdef HAVE_CXX11_UNORDERED_SET
+#include <unordered_map>
+#include <unordered_set>
+#else
 #include <tr1/unordered_map>
 #include <tr1/unordered_set>
+#endif
 
 class context {
 public:
@@ -75,10 +85,18 @@
  */
 class word_and_context_list {
 private:
+#ifdef HAVE_CXX11_UNORDERED_SET
+    typedef unordered_multimap<string,context> stopmap_t;
+#else
     typedef tr1::unordered_multimap<string,context> stopmap_t;
+#endif
     stopmap_t fcmap;			// maps features to contexts; for finding them
 
+#ifdef HAVE_CXX11_UNORDERED_SET
+    typedef unordered_set< string > stopset_t;
+#else
     typedef tr1::unordered_set< string > stopset_t;
+#endif
     stopset_t context_set;			// presence of a pair in fcmap
 
     beregex_vector patterns;
