--- src/lib/util/encode/binary_from_base16.h.orig	2015-09-12 06:08:57.358126000 +0900
+++ src/lib/util/encode/binary_from_base16.h	2015-09-12 06:09:12.997499000 +0900
@@ -93,9 +93,9 @@
 public:
     // make composable by using templated constructor
     template<class T>
-    binary_from_base16(BOOST_PFTO_WRAPPER(T)  start) :
+    binary_from_base16(T start) :
         super_t(
-            Base(BOOST_MAKE_PFTO_WRAPPER(static_cast<T>(start))), 
+            Base(static_cast<T>(start)), 
             detail::to_4_bit<CharType>()
         )
     {}
