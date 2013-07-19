--- third_party/WebKit/Source/wtf/TypeTraits.h	2013-07-04 00:14:12.000000000 -0400
+++ third_party/WebKit/Source/wtf/TypeTraits.h	2013-07-19 01:29:01.000000000 -0400
@@ -24,7 +24,7 @@
 
 #include <wtf/Platform.h>
 
-#if (defined(__GLIBCXX__) && (__GLIBCXX__ >= 20070724) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || (defined(_MSC_VER) && (_MSC_VER >= 1600))
+#if !COMPILER(CLANG) && ((defined(__GLIBCXX__) && (__GLIBCXX__ >= 20070724) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || (defined(_MSC_VER) && (_MSC_VER >= 1600)))
 #include <type_traits>
 #if defined(__GLIBCXX__) && (__GLIBCXX__ >= 20070724) && defined(__GXX_EXPERIMENTAL_CXX0X__)
 #include <tr1/memory>
