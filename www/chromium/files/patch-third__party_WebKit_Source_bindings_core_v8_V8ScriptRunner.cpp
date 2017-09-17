--- third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2017-09-05 21:05:39.000000000 +0200
+++ third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp	2017-09-07 17:51:16.350712000 +0200
@@ -49,6 +49,8 @@
 
 #if defined(OS_WIN)
 #include <malloc.h>
+#elif defined(OS_FREEBSD)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
