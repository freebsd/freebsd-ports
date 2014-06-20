--- src/index.h.orig	2013-11-28 09:39:20.000000000 +0100
+++ src/index.h	2014-05-01 12:12:57.000000000 +0200
@@ -36,7 +36,7 @@
 #endif
 ///////////////////////////////////////////
 
-#if defined UNORDERED_MAP && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(VISUALC)
+#if defined UNORDERED_MAP && !defined(__APPLE__) && !defined(__clang__) && !defined(VISUALC)
 #include <tr1/unordered_map>
 #define HASH_MAP_NAMESPACE std::tr1
 #define hash_map unordered_map
@@ -243,7 +243,7 @@
   // capacity of deg_t by direct addressing
   const int POLY_VARS=POLY_VARS_DIRECT+POLY_VARS_OTHER-1;
 
-#if defined(GIAC_NO_OPTIMIZATIONS) || ((defined(VISUALC) || defined(__APPLE__)) && !defined(GIAC_VECTOR))
+#if defined(GIAC_NO_OPTIMIZATIONS) || ((defined(VISUALC) || defined(__APPLE__) ||defined(__clang__)) && !defined(GIAC_VECTOR))
   class index_m {
   public:
     ref_index_t * riptr;
