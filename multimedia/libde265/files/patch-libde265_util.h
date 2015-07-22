--- libde265/util.h.orig	2015-07-22 16:48:18.032493000 +0200
+++ libde265/util.h	2015-07-22 16:48:43.439129000 +0200
@@ -70,7 +70,7 @@
 namespace std { using namespace std::tr1; }
 #endif
 
-#if __GNUC__ && GCC_VERSION < 40600
+#if __GNUC__ && GCC_VERSION < 40600 && !defined(__clang__)
 // nullptr was introduced in gcc 4.6, a simple alias should be fine for our use case
 #define nullptr NULL
 #endif
