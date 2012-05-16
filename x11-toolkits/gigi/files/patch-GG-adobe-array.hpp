--- GG/adobe/array.hpp.orig	2012-01-27 18:25:14.000000000 +0300
+++ GG/adobe/array.hpp	2012-01-27 18:26:35.000000000 +0300
@@ -33,7 +33,7 @@
 { v.push_back(any_regular_t(move(x))); }
 
 inline void push_back(array_t& v, any_regular_t x)
-{ v.push_back(move(x)); }
+{ v.push_back(::adobe::move(x)); }
 
 /**************************************************************************************************/
 
