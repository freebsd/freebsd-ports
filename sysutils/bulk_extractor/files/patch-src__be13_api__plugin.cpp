--- ./src/be13_api/plugin.cpp.orig	2013-08-18 16:35:29.000000000 +0000
+++ ./src/be13_api/plugin.cpp	2013-10-19 13:12:21.000000000 +0000
@@ -9,7 +9,16 @@
 #include <sys/stat.h>
 #include <dirent.h>
 #include <algorithm>
+#ifdef __clang__
+#if __has_include(<unordered_set>)
+#define HAVE_CXX11_UNORDERED_SET 1
+#endif
+#endif
+#ifdef HAVE_CXX11_UNORDERED_SET
+#include <unordered_set>
+#else
 #include <tr1/unordered_set>
+#endif
 #ifdef HAVE_ERR_H
 #include <err.h>
 #endif
@@ -23,20 +32,28 @@
 #include "../dfxml/src/hash_t.h"
 
 namespace std {
+#ifndef HAVE_CXX11_UNORDERED_SET
     namespace tr1 {
+#endif
         template<>
         struct hash<md5_t> {
             size_t operator()(const md5_t &key) const {
                 return *(size_t *)(key.final());
             }
         };
+#ifndef HAVE_CXX11_UNORDERED_SET
     }
+#endif
 }
 
 class atomic_hash_set 
 {
     cppmutex M;
+#ifdef HAVE_CXX11_UNORDERED_SET
+    std::unordered_set<md5_t>myset;
+#else
     std::tr1::unordered_set<md5_t>myset;
+#endif
 public:
     atomic_hash_set():M(),myset(){}
     bool in(const md5_t &s){
