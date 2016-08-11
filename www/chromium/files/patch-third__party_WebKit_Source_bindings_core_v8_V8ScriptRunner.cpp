--- third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2016-05-11 19:02:30 UTC
+++ third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp
@@ -44,6 +44,8 @@
 
 #if OS(WIN)
 #include <malloc.h>
+#elif OS(FREEBSD)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
