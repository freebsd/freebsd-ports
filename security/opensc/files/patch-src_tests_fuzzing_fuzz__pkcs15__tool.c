--- src/tests/fuzzing/fuzz_pkcs15_tool.c.orig	2022-11-30 08:11:53 UTC
+++ src/tests/fuzzing/fuzz_pkcs15_tool.c
@@ -23,7 +23,7 @@
 #include "config.h"
 #endif
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define _XOPEN_SOURCE 600
 #else
 #define _XOPEN_SOURCE 500
