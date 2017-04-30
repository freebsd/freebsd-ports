--- third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2017-04-19 19:06:49 UTC
+++ third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp
@@ -48,6 +48,8 @@
 
 #if OS(WIN)
 #include <malloc.h>
+#elif OS(FREEBSD)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
