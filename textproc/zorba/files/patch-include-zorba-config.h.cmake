--- include/zorba/config.h.cmake.orig	2014-06-13 15:08:16.000000000 +0200
+++ include/zorba/config.h.cmake	2014-06-13 15:08:29.000000000 +0200
@@ -126,7 +126,7 @@
 
 ////////// C++ tr1 include directory & namespace //////////////////////////////
 
-#if defined( __GNUC__ ) && (__GNUC__ * 100 + __GNUC_MINOR__ < 430)
+#if !defined(__clang__) && defined( __GNUC__ ) && (__GNUC__ * 100 + __GNUC_MINOR__ < 430)
 # define ZORBA_GCC_OLDER_THAN_430 1
 #endif
 
