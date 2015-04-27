--- third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2015-04-19 22:18:23.000000000 +0200
+++ third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp	2015-04-19 22:20:01.000000000 +0200
@@ -43,6 +43,8 @@
 
 #if defined(WTF_OS_WIN)
 #include <malloc.h>
+#elif defined(WTF_OS_FREEBSD)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
