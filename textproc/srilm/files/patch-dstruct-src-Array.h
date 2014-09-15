--- dstruct/src/Array.h.orig	2014-09-02 15:48:38.000000000 +0400
+++ dstruct/src/Array.h	2014-09-02 15:48:57.000000000 +0400
@@ -89,7 +89,7 @@ public:
  * gcc and icc allow this as part of the language, but many other C++ compilers
  * don't (Sun Studio, MS Visual C).
  */
-#if !defined(DEBUG) && defined(__GNUC__) && (!defined(__INTEL_COMPILER) || __INTEL_COMPILER >=900)
+#if !defined(DEBUG) && !defined(__clang__) && defined(__GNUC__) && (!defined(__INTEL_COMPILER) || __INTEL_COMPILER >=900)
 # define makeArray(T, A, n)		T A[n]
 #else
 # define makeArray(T, A, n)		StaticArray<T> A(n)
