--- src/3rdparty/chromium/v8/src/external-reference-table.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/v8/src/external-reference-table.cc
@@ -9,7 +9,7 @@
 #include "src/external-reference.h"
 #include "src/ic/stub-cache.h"
 
-#if defined(DEBUG) && defined(V8_OS_LINUX) && !defined(V8_OS_ANDROID)
+#if defined(DEBUG) && (defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)) && !defined(V8_OS_ANDROID)
 #define SYMBOLIZE_FUNCTION
 #include <execinfo.h>
 #include <vector>
