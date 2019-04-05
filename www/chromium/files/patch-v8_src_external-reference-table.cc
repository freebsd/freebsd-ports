--- v8/src/external-reference-table.cc.orig	2019-03-17 16:08:28 UTC
+++ v8/src/external-reference-table.cc
@@ -9,7 +9,7 @@
 #include "src/external-reference.h"
 #include "src/ic/stub-cache.h"
 
-#if defined(DEBUG) && defined(V8_OS_LINUX) && !defined(V8_OS_ANDROID)
+#if defined(DEBUG) && (defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)) && !defined(V8_OS_ANDROID)
 #define SYMBOLIZE_FUNCTION
 #include <execinfo.h>
 #include <vector>
