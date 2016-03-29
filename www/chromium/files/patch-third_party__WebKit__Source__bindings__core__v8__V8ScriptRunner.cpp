--- third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2016-03-14 18:32:33.447489424 +0100
+++ third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp	2016-03-14 19:58:58.005131694 +0100
@@ -43,6 +43,8 @@
 
 #if OS(WIN)
 #include <malloc.h>
+#elif OS(FREEBSD)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
