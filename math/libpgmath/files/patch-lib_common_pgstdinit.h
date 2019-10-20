--- lib/common/pgstdinit.h.orig	2019-10-20 14:27:37 UTC
+++ lib/common/pgstdinit.h
@@ -36,7 +36,7 @@ typedef unsigned long long size_t;
 #define _SIZE_T__
 #define _SIZE_T_DEFINED
 #define __SIZE_T__
-#if defined(LINUX8664) || defined(TARGET_OSX_X8664) || defined(TARGET_LLVM_64)
+#if defined(LINUX8664) || defined(TARGET_OSX_X8664) || defined(TARGET_LLVM_64) || defined(__FreeBSD__)
 typedef unsigned long size_t;
 #else
 typedef unsigned size_t;
