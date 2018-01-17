--- src/3rdparty/chromium/third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2017-01-26 00:49:27 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp
@@ -46,6 +46,8 @@
 
 #if OS(WIN)
 #include <malloc.h>
+#elif OS(FREEBSD)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
