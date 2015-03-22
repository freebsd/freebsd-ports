--- deps/v8/src/base/platform/platform.h.orig	2015-03-06 20:47:12.105304846 +0800
+++ deps/v8/src/base/platform/platform.h	2015-03-06 20:47:28.552291909 +0800
@@ -21,6 +21,7 @@
 #ifndef V8_BASE_PLATFORM_PLATFORM_H_
 #define V8_BASE_PLATFORM_PLATFORM_H_
 
+#include <stdio.h>
 #include <cstdarg>
 #include <string>
 #include <vector>
