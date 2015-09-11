--- src/lib/util/encode/binary_from_base32hex.h.orig	2015-09-12 06:05:44.329389000 +0900
+++ src/lib/util/encode/binary_from_base32hex.h	2015-09-12 06:06:24.217165000 +0900
@@ -96,9 +96,9 @@
 public:
     // make composable by using templated constructor
     template<class T>
-    binary_from_base32hex(BOOST_PFTO_WRAPPER(T)  start) :
+    binary_from_base32hex(T start) :
         super_t(
-            Base(BOOST_MAKE_PFTO_WRAPPER(static_cast<T>(start))), 
+            Base(static_cast<T>(start)), 
             detail::to_5_bit<CharType>()
         )
     {}
