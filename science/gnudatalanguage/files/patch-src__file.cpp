--- src/file.cpp.orig	2016-04-29 17:03:25 UTC
+++ src/file.cpp
@@ -242,10 +242,11 @@ extern "C"
 #endif
 #define NTEST_SEARCH 7
 
-#ifdef __CYGWIN__
+#if defined(__CYGWIN__) || defined(__FreeBSD__)
 #define stat64 stat
 #define lstat64 lstat
 // for religious reasons, CYGWIN doesn't do lstat64
+// FreeBSD doesn't do lstat64 because there is no need for it
 #endif
 
 namespace lib {
