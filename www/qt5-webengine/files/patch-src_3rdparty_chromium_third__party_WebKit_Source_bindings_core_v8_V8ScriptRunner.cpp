--- src/3rdparty/chromium/third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2017-04-11 12:57:39 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp
@@ -43,6 +43,8 @@
 
 #if OS(WIN)
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
