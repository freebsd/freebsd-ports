--- src/lib/util/encode/base32hex_from_binary.h.orig	2015-09-12 06:08:07.415328000 +0900
+++ src/lib/util/encode/base32hex_from_binary.h	2015-09-12 06:08:28.438126000 +0900
@@ -87,9 +87,9 @@
 public:
     // make composable by using templated constructor
     template<class T>
-    base32hex_from_binary(BOOST_PFTO_WRAPPER(T) start) :
+    base32hex_from_binary(T start) :
         super_t(
-            Base(BOOST_MAKE_PFTO_WRAPPER(static_cast<T>(start))),
+            Base(static_cast<T>(start)),
             detail::from_5_bit<CharType>()
         )
     {}
