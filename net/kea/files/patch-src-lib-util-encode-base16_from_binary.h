--- src/lib/util/encode/base16_from_binary.h.orig	2015-09-12 06:07:02.929641000 +0900
+++ src/lib/util/encode/base16_from_binary.h	2015-09-12 06:07:28.903859000 +0900
@@ -85,9 +85,9 @@
 public:
     // make composable by using templated constructor
     template<class T>
-    base16_from_binary(BOOST_PFTO_WRAPPER(T) start) :
+    base16_from_binary(T start) :
         super_t(
-            Base(BOOST_MAKE_PFTO_WRAPPER(static_cast<T>(start))),
+            Base(static_cast<T>(start)),
             detail::from_4_bit<CharType>()
         )
     {}
