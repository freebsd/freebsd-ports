--- src/libqhullcpp/QhullIterator.h.orig	2012-01-26 04:32:05.000000000 +0100
+++ src/libqhullcpp/QhullIterator.h	2014-12-19 15:19:26.000000000 +0100
@@ -16,8 +16,7 @@
 #include <assert.h>
 #include <string>
 #include <vector>
-//! Avoid dependence on <iterator>
-namespace std { struct bidirectional_iterator_tag; struct random_access_iterator_tag; }
+#include <iterator>
 
 namespace orgQhull {
 
